#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        for(int i = 1; i < height.size(); i++){
            left[i] = height[i - 1] > left[i - 1] ? height[i - 1] : left[i - 1];
        }
        vector<int> right(n);
        for(int j = n - 2; j > -1; j--){
            right[j] = height[j + 1] > right[j + 1] ? height[j + 1] : right[j + 1];
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            int h = min(left[i], right[i]);
            if(h > height[i]){
                sum += h - height[i];
            }
        }
        return sum;
    }
};