#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int max_length = 0;
        unordered_set<char> hash_set;
        for(int i = 0, j = 0; i < s.length(); i++){
            while(j < s.length() && hash_set.find(s[j]) == hash_set.end()){
                hash_set.insert(s[j]);
                j++;
            }
            max_length = max(max_length, j - i);
            if(j == s.length()){
                break;
            }
            hash_set.erase(s[i]);
        }
        return max_length;
    }
};