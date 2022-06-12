#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
		while( i < s.length()){
			if(s[i] == ' '){
                i++;
				continue;
			}
			int j = i;
			while(j < s.length() && s[j] != ' '){
				j++;
			}
			int k = j - 1;
			while(i < k){
				int temp = s[i];
				s[i] = s[k];
				s[k] = temp;
                i++;
                k--;
			}
			i = j + 1;
		}
		return s;
    }
};