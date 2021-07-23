1893. Check if All the Integers in a Range Are Covered
------------------------------------------------------

[problem description](https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered/)

Solution
```
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        for(auto&& range:ranges){
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }
        int presum = 0;
        int i = 1;
        while(i < 51){
            presum += diff[i];
            if(i >= left && i <= right){
                if(presum == 0){
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};
```