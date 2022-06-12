#include <vector>
#include <deque>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	/**
	 * 使用双端队列来打印
	 * 另一种算法是打印到双端的列表
	 * 不过C++里面的话就得用insert，这样的话加入队列的时间就不是O(1)了
	 */
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if(root == nullptr){
			return res;
		}
		deque<TreeNode*> q;
		q.push_back(root);
		while(q.empty() ==false){
			vector<int> row;

			// 通常bfs是一个一个取队列中的，这里每一轮取得是一层的，这样就简化了问题。
            int size = q.size();// 这里很重要，因为如果写成for循环的条件的话q.size()会变化，size就不固定了
			for(int i = 0; i < size; i++){
				TreeNode* node;
				if(res.size() % 2 == 0){
					node = q.front();
					row.push_back(node->val);
					q.pop_front();
					if(node->left){
						q.push_back(node->left);
					}
					if(node->right){
						q.push_back(node->right);
					}
				}
				else{
					node = q.back();
					row.push_back(node->val);
					q.pop_back();
					if(node->right){
						q.push_front(node->right);
					}
					if(node->left){
						q.push_front(node->left);
					}
				}
			}
			res.push_back(row);
		}
		return res;
    }
};