#include <vector>
#include <stack>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        stack<Node*> stk;
        stk.push(root);
        while(stk.empty() == false){
            Node* cur = stk.top();
            ans.push_back(cur->val);
            stk.pop();
            for(int i = cur->children.size() - 1; i > -1; i--){
                stk.push(cur->children[i]);
            }
        }
        return ans;
    }

	vector<int> preorderRecursive(Node* root){
		vector<int> ans;
		traverse(root, ans);
		return ans;
	}

private:
    void traverse(Node* root, vector<int>& ans){
        if(root == nullptr){
            return ;
        }
        ans.push_back(root->val);
        for(auto node : root->children){
            traverse(node, ans);
        }
    }
};