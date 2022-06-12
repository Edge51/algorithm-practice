class Solution {
public:
    int numWays(int n) {
		int a = 1;
		int b = 1;
		int result = 0;
		for(int i = 2; i <= n; i++){
			result = (a + b) % 1000000007;
			a = b;
			b = result;
		}
		return result;
    }
};

int main(){
}