class Solution{
public:
	int addDigits(int num){
		if(num < 10){
			return num;
		}
		int sum;
		while(num >= 10){
			sum = 0;
			while(num){
				sum += num % 10;
				num /= 10;
			}
			num = sum;
		}
		return sum;
	}

	/**可以分析得到num与最后的树根关于9同余
	 * num = 0 时 结果为0
	 * num > 0 && num % 9 == 0: result = 9
	 * 所以考虑 (num - 1) % 9 + 1;
	 * 同时，细节上需要考虑 (0-1) % 9 
	 * 对于C++而言-1 % 9 = -1
	 */
	int addDigitsMath(int num){
		return (num - 1) % 9 + 1;
	}
private:
};