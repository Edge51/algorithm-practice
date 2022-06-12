#include <iostream>
#include <vector>
using namespace std;


// 根据题目条件数字在0～数组长度范围内，原地修改测试
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int k = nums[i];
            if(k < 0) k += n;//不是第一次访问，被修改过，先恢复再测试
            if(nums[k] < 0) return k;
            nums[k] -= n;//第一次访问时，把数字修改成负数
        }

        return -1;
    }
};
