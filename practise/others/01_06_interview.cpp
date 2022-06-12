#include <string>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        int i = 0;
        string ans;
        while(i < S.length()){
            int j = i;
            ans += S[i];
            int count = 0;
            while(S[j] == S[i]){
                j++;
                count++;
            }
            ans += to_string(count);
            i = j;
        }
        if(ans.length() >= S.length()){
            return S;
        }
        return ans;
    }
};
