#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
		int n = array.size();
		int m = array[0].size();
		int row = 0;
		int column = m - 1;
		while(row < n && column >= 0){
			if(array[row][column] == target){
				return true;
			}else if(array[row][column] > target){
				column = column - 1;
			}else if(array[row][column] < target){
				row = row + 1;
			}
		}
		return false;
    }
};