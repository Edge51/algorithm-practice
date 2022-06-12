#include <iostream>
#include <vector>
#include <climits>
#include <random>
#include <algorithm>
using namespace std;

/** 209. 长度最小的子数组
	给定一个含有 n 个正整数的数组和一个正整数 target 。

	找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

	 

	示例 1：

	输入：target = 7, nums = [2,3,1,2,4,3]
	输出：2
	解释：子数组 [4,3] 是该条件下的长度最小的子数组。
	示例 2：

	输入：target = 4, nums = [1,4,4]
	输出：1
	示例 3：

	输入：target = 11, nums = [1,1,1,1,1,1,1,1]
	输出：

	来源：力扣（LeetCode）
	链接：https://leetcode.cn/problems/minimum-size-subarray-sum
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		int min_length = INT_MAX;
		vector<int> pre_sum(n + 1, 0);
		for(int i = 1; i < n + 1; i++){
			// don't forget to add pre_sum[i - 1]
			pre_sum[i] += nums[i - 1] + pre_sum[i - 1];
		}
		for(int i = 0; i < n; i++){
			int j = binarySearch(pre_sum, target + pre_sum[i]);
			if(j != -1){
				//index of pre_sum already +1
				// so the length is j - i instead of j - i + 1
				min_length = min(min_length, j - i);
			}
		}
		return min_length == INT_MAX ? 0 : min_length;
	}
	int binarySearch(vector<int> sum, int target){
		int left = 0;
		int right = sum.size() - 1;
		while(left < right){
			int mid = left + (right - left) / 2;
			if(sum[mid] < target){
				left = mid + 1;
			}else{
				right = mid;
			}
		}
		return sum[left] >= target ? left : -1;
	}

	// 滑动窗口，两个指针i, j，扫描一遍。
    int minSubArrayLen2(int target, vector<int>& nums) {
		int i = 0, j = 0;
		int sum = nums[0];
		int minLength = INT_MAX;
		while(i <= j && j < nums.size()){
			while(sum < target){
				j++;
                if(j >= nums.size()){
                    break;
                }
				sum += nums[j];
			}
			while(i <= j && sum >= target){
				int current_length = j - i + 1;
				if(current_length < minLength){
					minLength = current_length;
				}
				sum -= nums[i];
				i++;
			}
		}
		if(minLength == INT_MAX){
			return 0;
		}
		return minLength;
	}

	// 时间复杂度 n*n
	// 暴力搜索
    int minSubArrayLen1(int target, vector<int>& nums) {
		if(nums.size() == 0){
			return 0;
		}
		int minLength = INT_MAX;
		for(int i = 0; i < nums.size(); i++){
			int sum = 0;

			for(int j = i; j < nums.size(); j++)
				sum += nums[j];
				if(sum >= target){
					minLength = min(minLength, j - i + 1);
					break;
				}
			}
		}
		return minLength == INT_MAX ? 0 : minLength;
    }
};

int main(int argc, char* argv){
	if(argc != 2){
		cout << "Error usage." << endl;
		cout << "Example: test 100" << endl;
	}
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 1000);
	int number_of_test_case = distribution(generator);
	Solution solution;
	while(number_of_test_case--){
		int target = distribution(generator);
		uniform_int_distribution<int> arr_distribution(1, target);
		vector<int> arr;
		int arr_length = distribution(generator);
		for(int i = 0; i < arr_length; i++){
			arr.push_back(arr_distribution(generator));
		}
		solution.minSubArrayLen(target, arr);
	}
	return 0;
}
