#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int maxSum = -9999999;
        maxPathSumCal(root, maxSum);
        return maxSum;
    }
private:
    int maxPathSumCal(TreeNode* root, int& maxSum){
        if(root == nullptr){
            return 0;
        }
        int leftGain = max(maxPathSumCal(root->left, maxSum), 0);
        int rightGain = max(maxPathSumCal(root->right, maxSum), 0);
        maxSum = max(leftGain + root->val + rightGain, maxSum);
        
        return leftGain > rightGain ? leftGain + root->val : rightGain + root->val;
    }
};