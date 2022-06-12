/** 用左子树的大小来计算右子树的左边界
 *  用哈希映射来代替find函数： index[inorder[i]] = i;
 *  每次递归的时候要记得左边界右边界会跟着改变的，不要一直用0和size()-1
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return nullptr;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright){

        if(preleft > preright){
            return nullptr;
        }

        TreeNode* ans = new TreeNode(preorder[preleft]);

        int inmid = find(inorder, preorder[preleft]);
        int leftTreeSize = inmid - inleft;
        if(inmid > inleft ){
            ans->left = build(preorder, preleft + 1, preleft + leftTreeSize, inorder, inleft, inmid - 1);
        }

        if(inmid < inright){
            ans->right = build(preorder, preleft + leftTreeSize + 1, preright, inorder, inmid + 1, inright);
        }

        return ans;
    }
    int find(vector<int> arr, int target){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }
};

void printTree(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	while(root){
		TreeNode* cur = q.front();
		q.pop();
		cout << cur->val << " ";
		if(cur->left){
			q.push(cur->left);
		}
		if(cur->right){
			q.push(cur->right);
		}
	}
	cout << endl;
}

int main(){
	vector<int> preorder;
	preorder.push_back(3);
	preorder.push_back(9);
	preorder.push_back(20);
	preorder.push_back(15);
	preorder.push_back(7);
	vector<int> inorder;
	inorder.push_back(9);
	inorder.push_back(3);
	inorder.push_back(15);
	inorder.push_back(20);
	inorder.push_back(7);
	Solution solution;
	TreeNode* root = solution.buildTree(preorder, inorder);
	printTree(root);
	return 0;
}

