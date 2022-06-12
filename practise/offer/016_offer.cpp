class Solution{
public:
	/** runtime error because of overflow 65536*65536 is not int
	 * 
	 */
	double myPowRuntimeError(int x, int n){
		int res = 1;
		while(n> 0){
			if(n&1 == 1){
				res *= x;
			}
			x = x * x;
			n >> 1;
		}
		return x * res;
	}

	double myPow(double x, int n){
		if(x == 0){
			return 0;
		}
		double res = 1;
        long nn = (long) n; // int中的最小值-2147483648没有正数，转换为long可以解决。
		if(n < 0){
			x = 1 / x;
            nn = -nn;
		}
		while(nn){
			if(nn&1 == 1){
				res *= x;
			}
			nn >>= 1;
			x = x * x;
		}
		return res;
	}
private:
};