#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
		stack<int> stk;
		int cur = 0;
		for(int node:pushed){
			stk.push(node);
			while(stk.empty() == false && stk.top() == popped[cur]){
				stk.pop();
				cur++;
			}
		}
		return stk.empty();
	}

	// 用出栈序列检查压栈序列，优化
    bool validateStackSequencesImprove(vector<int>& pushed, vector<int>& popped) {
		stack<int> stk;
		int cur = 0;
		for(int i = 0; i < popped.size(); i++){
			while(stk.empty() == true || stk.top() != popped[i]){
				if(cur >= pushed.size()){
					return false;
				}
				else{
					stk.push(pushed[cur]);
					cur++;
				}
			}
			stk.pop();
		}
		return stk.empty();
    }

	// 用出栈序列检查压栈序列，麻烦
    bool validateStackSequencesComplicated(vector<int>& pushed, vector<int>& popped) {
		stack<int> stk;
		int cur = 0;
		for(int i = 0; i < popped.size(); i++){
			if(stk.empty() != true){
				if(stk.top() == popped[i]){
					stk.pop();
					continue;
				}
				else{
					while(cur < pushed.size() && pushed[cur] != popped[i]){
						stk.push(pushed[cur]);
						cur++;
					}
					if(cur == pushed.size()){
						return false;
					}
					else{
						cur++;
						continue;
					}
				}
			}
			else{
				while(cur < pushed.size() && pushed[cur] != popped[i]){
					stk.push(pushed[cur]);
					cur++;
				}
				if(cur == pushed.size()){
					return false;
				}
				else{
					cur++;
					continue;
				}
			}
		}
		if(stk.empty() == false){
			return false;
		}
		return true;
    }
};