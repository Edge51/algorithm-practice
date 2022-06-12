#include <vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if(matrix.size() == 0){
			return {};
		}
		int top = 0;
		int left = 0;
		int right = matrix[0].size() - 1;
		int bottom = matrix.size() - 1;
		vector<int> res;
		while(true){
			for(int i = left; i < right + 1; i++){
				res.push_back(matrix[top][i]);
			}
			top++;
			if(top > bottom){
				break;
			}
			for(int i = top; i < bottom + 1; i++){
				res.push_back(matrix[i][right]);
			}
			right--;
			if(left > right){
				break;
			}
			for(int i = right; i > left - 1; i--){
				res.push_back(matrix[bottom][i]);
			}
			bottom--;
			if(top > bottom){
				break;
			}
			for(int i = bottom; i > top - 1; i--){
				res.push_back(matrix[i][left]);
			}
			left++;
			if(left > right){
				break;
			}
		}
		return res;
	}
	
	// stupid to calculate the border
    vector<int> spiralOrderWrongAns(vector<vector<int>>& matrix) {
		vector<int> res;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for(int round = 0; round < rows / 2; round++){
			for(int i = round; i < cols - round - 1; i++){
				res.push_back(matrix[round][i]);
			}
			for(int i = round; i < rows - round - 1; i++){
				res.push_back(matrix[i][cols - round - 1]);
			}
			for(int i = cols - round - 1; i > round + 1; i--){
				res.push_back(matrix[rows - round - 1][i]);
			}
			for(int i = rows - round - 1; i > round + 1; i--){
				res.push_back(matrix[round][i]);
			}
		}
		if(rows % 2 == 1){
			for(int i = rows / 2; i < cols - rows / 2 - 1; i++){
				res.push_back(matrix[rows / 2][i]);
			}
			res.push_back((matrix[rows / 2][cols - rows / 2 - 1]));
		}
		return res;
    }
};