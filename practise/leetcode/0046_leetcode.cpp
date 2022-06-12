#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0){
            return ans;
        }
        vector<int> empty;
        dfs(ans, nums, empty);
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int> nums, vector<int> subAns){
        if(nums.size() == 1){
            subAns.push_back(nums[0]);
            ans.push_back(subAns);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            subAns.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            dfs(ans, nums, subAns);
            nums.insert(nums.begin() + i, subAns.back());
            subAns.pop_back();
        }
        return ;
    }
};
