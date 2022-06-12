#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
		if(root == nullptr){
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		while(q.empty() ==false){
			vector<int> row;

			// 通常bfs是一个一个取队列中的，这里每一轮取得是一层的，这样就简化了问题。
            int size = q.size();// 这里很重要，因为如果写成for循环的条件的话q.size()会变化，size就不固定了
			for(int i = 0; i < size; i++){
				TreeNode* node = q.front();
				row.push_back(node->val);
				if(node->left){
					q.push(node->left);
				}
				if(node->right){
					q.push(node->right);
				}
				q.pop();
			}
			res.push_back(row);
		}
		return res;
    }
	
    vector<vector<int>> levelOrderError(TreeNode* root) {
		vector<vector<int>> res;
		if(root == nullptr){
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		int round = 0;
		int count = 0;
		int num = pow(2, round);
		while(q.empty() == false){
			TreeNode* node = q.front();
			q.pop();
			if(res.size() <= round){
				res.push_back(vector<int>());
			}
			if(count < num){
				if(node){
					res[round].push_back(node->val);
				}
				count++;
			}
			else{
				round++;
				num = pow(2, round);
				count = 0;
				res.push_back(vector<int>());
			}
			if(node){
				q.push(node->left);
				q.push(node->right);
			}
		}
		res.pop_back();
		return res;
    }
};