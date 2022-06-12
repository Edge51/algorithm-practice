#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] < 0 - nums[i]){
                    left++;
                }else if(nums[left] + nums[right] == 0 - nums[i]){
                    ans.push_back(vector<int>({nums[i], nums[left], nums[right]}));
                    left++;
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};