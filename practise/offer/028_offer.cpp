#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
	bool isSymmetricRecursive(TreeNode* root){
		if(root == nullptr){
			return true;
		}
		return symmetricForSubtreeRecursive(root->left, root->right);
	}

	bool isSymmetricLoop(TreeNode* root){
		if(root == nullptr){
			return true;
		}
		queue<TreeNode*> node_queue;
		node_queue.push(root->left);
		node_queue.push(root->right);
		while(node_queue.empty() != true){
			TreeNode* left = node_queue.front();
			node_queue.pop();
			TreeNode* right = node_queue.front();
			node_queue.pop();
			if(left == nullptr && right == nullptr){
				continue;
			}else if(left == nullptr || right == nullptr || left->val != right->val){
				return false;
			}else{
				node_queue.push(left->left);
				node_queue.push(right->right);
				node_queue.push(left->right);
				node_queue.push(right->left);
			}
		}
		return true;
	}
private:
	bool symmetricForSubtreeRecursive(TreeNode* left, TreeNode* right){
		if(left == nullptr && right == nullptr){
			return true;
		}
		if(left == nullptr || right == nullptr || left->val != right->val){
			return false;
		}
		bool bool1 = symmetricForSubtreeRecursive(left->left, right->right);
		bool bool2 = symmetricForSubtreeRecursive(left->right, right->left);
		return bool1 && bool2;
	}
};