#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	/**
	 * 动态规划，类似前缀和
	 */
	vector<int> goodDaysToRobBank(vector<int>& security, int time){
		vector<int> ans;
		int n = security.size();
		vector<int> front(n);
		vector<int> back(n);

		for(int i = 1, j = n - 2; i < n, j >= 0; i++, j--){
			if(security[i] <= security[i - 1]){
				front[i] = front[i - 1] + 1;
			}
			if(security[j] <= security[j + 1]){
				back[j] = back[j + 1] + 1;
			}
		}
		for(int i = time; i < n - time; i++){
			if(front[i] >= time && back[i] >= time){
				ans.push_back(i);
			}
		}
		return ans;
	}

	/**
	 * 维护两个队列去存元素前的符合条件的序列
	 * 若队列长等于time则说明当前节点为合适打劫的日子
	 */
    vector<int> goodDaysToRobBankTwoQueueCheck(vector<int>& security, int time) {
		vector<int> ans;
		if(security.size() <= 2 * time){
			return ans;
		}
        if(time == 0){
            for(int i = 0; i < security.size(); i++){
                ans.push_back(i);
            }
            return ans;
        }
		queue<int> increase;
		queue<int> decrease;
		for(int i = 0; i < time; i++){
			inqueue(increase, security[i], -1);
		}
		for(int i = time + 1; i < 2 * time + 1; i++){
			inqueue(decrease, security[i], 1);
		}
		if(increase.size() == time && decrease.size() == time && increase.front() >= security[time] && decrease.front() >= security[time]){
			ans.push_back(time);
		}
		for(int i = time + 1; i + time < security.size(); i++){
            if(increase.size() >= time){
                increase.pop();
            }
            if(decrease.size() >= time){
                decrease.pop();
            }
			inqueue(increase, security[i - 1], -1);
			inqueue(decrease, security[i + time], 1);
            //cout << "line " << i << ": " << increase.front() << " " << decrease.front() << " " << increase.size() << " " << decrease.size() << endl;
			if(increase.size() == time && decrease.size() == time && increase.back() >= security[i] && decrease.front() >= security[i]){
				ans.push_back(i);
			}
		}
		return ans;
    }
private:
	void inqueue(queue<int>& q, int val, int lessOrMore){
		if(q.empty()){
			q.push(val);
		}
		else{
			if(judgeAccordFlag(val, q.back(), lessOrMore)){
				while(q.empty() == false){
					q.pop();
				}
				q.push(val);
			}
			else{
				q.push(val);
			}
		}
	}
	bool judgeAccordFlag(int a, int b, int flag){
		if(flag == 1){
			if(a < b){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if(a > b){
				return true;
			}
			else{
				return false;
			}
		}
		return true;
	}
};