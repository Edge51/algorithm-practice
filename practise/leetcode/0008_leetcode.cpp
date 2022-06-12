#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
		int sign = 1;
		long long ans = 0;
		string state = "start";
		for(char c : s){
			state = table[state][choice(c)];
			if(state == "in_number"){
				ans = ans * 10 + c - '0';
				ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
			}
			else if(state == "signed"){
				sign = c == '+' ? 1 : -1;
			}
		}
		return ans * sign;
    }
private:
	unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
	};

	int choice(char c){
		if(c == ' ') return 0;
		if(c == '+' || c == '-') return 1;
		if(c <= '9' && c >= '0') return 2;
		return 3;
	}
};