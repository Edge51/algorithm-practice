#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for(int i = 0; i < strs[0].length(); i++){
            char c = strs[0][i];
            bool same = true;
            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].length()){
                    return ans;
                }
                if(strs[j][i] != c){
                    same = false;
                    break;
                }
            }
            if(same == true){
                ans += c;
            }else{
                return ans;
            }
        }
        return ans;
    }
};