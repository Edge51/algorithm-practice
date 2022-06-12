#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string result = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                result += s[i];
            }else{
                result += "%20";
            }
        }
        return result;
    }
	
	// replace space with no new string
	string replaceSpaceNoNewString(string s){
		int count = 0;
		int length = s.length();
		for(char c:s){
			if(c == ' '){
				count++;
			}
		}
		s.resize(length + 2 * count);
		for(int i = length - 1, j = s.size() - 1; i >= 0; i--){
			if(s[i] == ' '){
				s[j--] = '0';
				s[j--] = '2';
				s[j--] = '%';
			}else{
				s[j--] = s[i];
			}
		}
		return s;
	}
};

int main(){
	vector<int> temp;
}
