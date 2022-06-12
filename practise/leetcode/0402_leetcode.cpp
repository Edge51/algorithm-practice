#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	string removeKdigits(string num, int k){
		vector<char> stk;
		int count = 0;
		for(int i = 0; i < num.length(), count < k; i++){
			while(count < k && stk.size() > 0 && stk.back() > num[i]){
				stk.pop_back();
				count++;
			}
			stk.push_back(num[i]);
		}
		if(count < k){
			stk.pop_back();
			count++;
		}
		int i = 0;
		while(stk[i] == '0'){
			i++;
		}
		string ans;
		while(i < stk.size()){
			ans += stk[i];
		}
		if(ans == ""){
			return "0";
		}
		return ans;
	}

	/**
	 * TLE了，算法复杂度为O(nk)，应该用栈优化
	 */
    string removeKdigitsTLE(string num, int k) {
        if(num.length() <= k){
            return "0";
        }
        for(int i = 0; i < k; i++){
            int j = 0;
            while(j < num.length() - 1 && num[j] <= num[j + 1]){
                j++;
            }
            if(j == num.length() - 1){
                num.pop_back();
            }else if(j < num.length() - 1){
                num.erase(j, 1);
            }
            // cout << num << endl;
        }
        int i = 0;
        while(num[i] == '0'){
            i++;
        }
        if(i < num.length()){
            return num.substr(i);
        }
        return "0";
    }
};