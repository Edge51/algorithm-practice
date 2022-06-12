#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> route;
        int sum = 0;
        dfs(root, ans, route, sum, target);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<vector<int>> & ans, vector<int> route, int sum, int target){
        if(root == nullptr){
            return ;
        }
        sum += root->val;
        route.push_back(root->val);
        if(sum == target && root->left == nullptr && root->right == nullptr){
            ans.push_back(route);
        }
        dfs(root->left, ans, route, sum, target);
        dfs(root->right, ans, route, sum, target);
    }
};