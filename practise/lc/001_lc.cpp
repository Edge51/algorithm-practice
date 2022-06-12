#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
        unordered_map<int, int> hash_map;
		for(int i = 0; i < nums.size(); i++){
			unordered_map<int, int>::const_iterator tar = hash_map.find(target - nums[i]);
			if(tar != hash_map.end()){
				res.push_back(hash_map[nums[i]]);
				res.push_back(i);
				return res;
			}
			// 匹配完再添加，防止自己匹配自己
			hash_map[nums[i]] = i;
		}
		return res;
    }
};