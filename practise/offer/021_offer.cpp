#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
		int i = 0;
		int length = nums.size();
		int j = length - 1;
		while(i<j){
			while(i < length && nums[i] % 2 == 1){
				i++;
			}
			while(j >= 0 && nums[j] % 2 == 0){
				j--;
			}
			if(i < j){
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
		return nums;
    }

	// improve by remove the variable length
    vector<int> exchange2(vector<int>& nums) {
		int i = 0;
		int j = nums.size() - 1;
		while(i<j){
			while(i < j && nums[i] % 2 == 1){
				i++;
			}
			while(i < j && nums[j] % 2 == 0){
				j--;
			}
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
		return nums;
    }
};