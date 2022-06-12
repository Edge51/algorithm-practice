#include <vector>
using namespace std;

class Solution {
public:
	/**
	 * 动态规划: maxsum[i] = max(maxsum[i - 1] + nums[i], nums[i])
	 * maxsum[i]表示以i为末元素的最大子数组和
	 */
    int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int max = nums[0];
		for(int i = 1; i < nums.size(); i++){
			if(sum >= 0){
				sum = sum + nums[i];
			}
			else{
				sum = nums[i];
			}
			if(max < sum){
				max = sum;
			}
		}
		return max;
    }
};