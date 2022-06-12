#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	// 单调栈
	bool verifyPostorder(vector<int>& postorder){
		stack<int> stk;
		int root = 999999;
		for(int i = postorder.size() - 1; i >= 1; i--){
			if(postorder[i] > root){
				return false;
			}
			else{
				while(stk.empty() == false && postorder[i] < stk.top()){
					root = stk.top();
					stk.pop();
				}
				stk.push(postorder[i]);
			}
		}
		return true;
	}

	// 递归分治
    bool verifyPostorderNormal(vector<int>& postorder) {
		return verify(postorder, 0, postorder.size() - 1);
    }
private:

	// 递归
	bool verify(vector<int>& postorder, int left, int right){
		if(left == right){
			return true;
		}
		int j = right - 1;
		while(j > left - 1 && postorder[j] > postorder[right]){
			j--;
		}
		if(j < left){
			return verify(postorder, left, right - 1);
		}
		int pivot = j;
		while(j > left - 1){
			j--;
			if(postorder[j] > postorder[right]){
				return false;
			}
		}
		return verify(postorder, left, pivot) && verify(postorder, pivot, right - 1);
	}
};