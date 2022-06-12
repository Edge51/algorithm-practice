#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights){
		int n = heights.size();
		stack<int> stk;
		vector<int> left(n);
		vector<int> right(n, n);
		for(int i = 0; i < n; i++){
			while(stk.empty() == false && heights[stk.top()] >= heights[i]){
				right[stk.top()] = i;
				stk.pop();
			}
			if(stk.empty()){
				left[i] = -1;
			}
			else{
				left[i] = stk.top();
			}
			stk.push(i);
		}

		int max = -1;
		for(int i = 0; i < n; i++){
			int area = heights[i] * (right[i] - left[i] - 1);
			if( area > max){
                // cout << area << " " << i <<": " << heights[i] << " " << left[i] << " " << right[i] << endl;
				max = area;
			}
		}
		return max;
	}

	// double stack
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
		if(n == 1){
			return heights[0];
		}
		stack<int> left_stk;
		stack<int> right_stk;
		vector<int> left(n);
		vector<int> right(n);
		for(int i = 0; i < n; i++){
			while(left_stk.empty() == false && heights[left_stk.top()] >= heights[i]){
				left_stk.pop();
			}
			if(left_stk.empty()){
				left[i] = -1;
			}
			else{
				left[i] = left_stk.top();
			}
			left_stk.push(i);
			while(right_stk.empty() == false && heights[right_stk.top()] >= heights[n - i - 1]){
				right_stk.pop();
			}
			if(right_stk.empty()){
				right[n - i - 1] = n;

			}
			else{
				right[n - i - 1] = right_stk.top();
			}
			right_stk.push(n - i - 1);
		}

		int max = -1;
		for(int i = 0; i < n; i++){
			int area = heights[i] * (right[i] - left[i] - 1);
			if( area > max){
                // cout << area << " " << i <<": " << heights[i] << " " << left[i] << " " << right[i] << endl;
				max = area;
			}
		}
		return max;
	}
};