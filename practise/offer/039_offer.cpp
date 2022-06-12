#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
	int majorityElementHashmap(vector<int>& nums){
		unordered_map<int, int> counts;
		int max = nums[0];
		for(auto num:nums){
			counts[num]++;
			if(counts[num] > nums.size() / 2){
				return num;
			}
			if( counts[num] > counts[max] ){
				max = num;
			}
		}
		return max;
	}

	// 投票法
	int majorityElement(vector<int>& nums){
		int res = nums[0];
		int count = 1;
		for( int i = 1; i < nums.size(); i++){
			if(count == 0){
				res = nums[i];
				count++;
				continue;
			}
			if(nums[i] != res){
				count--;
			}else{
				count++;
			}
		}
		return res;
	}
private:

};