#include <iostream>
#include <string>
#include <random>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
		return "";
    }
};

string generateRandomString(int length){
	const string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int CHARACTERS_LENGTH = CHARACTERS.length();
	string ans;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, CHARACTERS_LENGTH);
	for(int i = 0; i < length; i++){
		ans.append(1, CHARACTERS[distribution(generator)]);
	}
	return ans;
}

int main(int argc, char* argv[]){
	cout << generateRandomString(10) << endl;
	return 0;
}