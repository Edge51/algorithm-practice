#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> w(n);
	int k = 0;
	long d = 0;
	for(int i = 0; i < n; i++){
		cin >> a[k] >> b[k] >> w[k];
		b[k] = b[k] - (a[k] - b[k]);
		if(b[k] <= 0){
			x += -b[k];
			d += w[k];
		}else{
			k++;
		}
	}
	vector<long> dp(x + 1);
	for(int i = 0; i < k; i++){
		for(int j = x; j >= b[i]; j--){
			dp[j] = max(dp[j], dp[j - b[i]] + w[i]);
		}
	}
	cout << dp[x] + d << endl;
}