#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int n = s.length();
		vector<int> pre_plate(n);
		int count = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '*'){
				count++;
			}
			pre_plate[i] = count;
		}
		vector<int> left(n);
		for(int i = 0, l = -1; i < n; i++){
			if(s[i] == '|'){
				l = i;
			}
			left[i] = l;
		}
		vector<int> right(n);
		for(int i = n - 1, l = n; i > -1; i--){
			if(s[i] == '|'){
				l = i;
			}
			right[i] = l;
		}
		vector<int> ans;
		for(auto q : queries){
			int x = right[q[0]];
			int y = left[q[1]];
			if(x == -1 || y == n || x >= y){
				ans.push_back(0);
			}
			else{
				ans.push_back(pre_plate[y] - pre_plate[x]);
			}
		}
		return ans;
    }
};