#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution{
public:
	bool exist(vector<vector<char> >& board, string word){
		int rows = board.size();
		int columns = board[0].size();
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				if(dfs(board, word, i, j, 0)){
					return true;
				}
			}
		}
		return false;
	}
private:
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
		int rows = board.size();
		int columns = board[0].size();
		if(i < 0 || j < 0 || i >= rows || j >= columns || board[i][j] != word[k]){
			return false;
		}
		if(k == word.length() - 1){
			return true;
		}
		board[i][j] = '\0';
		if(dfs(board, word, i, j + 1, k + 1)\
			|| dfs(board, word, i, j - 1, k + 1)\
			|| dfs(board, word, i - 1, j, k + 1)\
			|| dfs(board, word, i + 1, j, k + 1)){
				return true;
			}
		board[i][j] = word[k];
		return false;
	}
};