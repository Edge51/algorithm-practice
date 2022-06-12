#include <vector>
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
    int kthLargest(TreeNode* root, int k) {
		vector<TreeNode*> arr;
		inorderTraversalVector(arr, root);
		return arr[k -1]->val;
    }
	
	// use count instead of vector
	int kthLargestIterate(TreeNode* root, int k) {
		int count = 0;
		int ans;
		inorderTraversalIterate(root, k, count, ans);
		return ans;
    }
private:
	void inorderTraversalIterate(TreeNode* root, const int& k, int& count, int& ans){
		if(root->right != nullptr){
			inorderTraversalIterate(root->right, k, count, ans);
		}
		count++;
		if(count == k){
			ans = root->val;
			return;
		}else if(count > k){
			return;
		}
		if(root->left != nullptr){
			inorderTraversalIterate(root->left, k, count, ans);
		}
	}
	void inorderTraversalVector(vector<TreeNode*>& arr, TreeNode*root){
		if(root->right != nullptr){
			inorderTraversalVector(arr, root->right);
		}
		arr.push_back(root);
		if(root->left != nullptr){
			inorderTraversalVector(arr, root->left);
		}
	}
};