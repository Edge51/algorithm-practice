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
	// new新的节点返回，速度比用原来的节点快很多，但是消耗内存大
    TreeNode* mirrorTree(TreeNode* root) {
		if(root == nullptr){
			return root;
		}
		TreeNode* res = new TreeNode(root->val);
		res->left = mirrorTree(root->right);
		res->right = mirrorTree(root->left);
		return res;
    }

	// 使用原来的树的节点返回，空间消耗小但速度慢很多
	TreeNode* mirrorTreeNoNew(TreeNode* root) {
		if(root == nullptr){
			return root;
		}
		TreeNode* temp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(temp);
		return root;
	}
};