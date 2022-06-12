#include <string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        string sign = "";
		if(num < 0){
			sign += '-';
			num = -num;
		}
		string ans = "";
		while(num){
			int digit = num % 7;
			num = num / 7;
			ans = (char)('0' + digit) + ans;
        }
		ans = sign + ans;
		return ans;
    }
};