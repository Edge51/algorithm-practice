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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
		if(B == nullptr){
			return false;
		}
		if(A == nullptr){
			return false;
		}
		if(isSameStructure(A, B)){
			return true;
		}
		return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
private:
	bool isSameStructure(TreeNode* A, TreeNode* B){
		if(B == nullptr){
			return true;
		}
		if(A == nullptr){
			return false;
		}
		if(A->val != B->val){
			return false;
		}
		return isSameStructure(A->left, B->left) && isSameStructure(A->right, B->right);
	}
};