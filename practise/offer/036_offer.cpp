#include <iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* ans;
        Node* findLeftMost = root;
        while(findLeftMost){
            if(findLeftMost->left){
                findLeftMost = findLeftMost->left;
            }else{
                break;
            }
        }
        connect(root);
        ans = findLeftMost;
        while(findLeftMost->right){
            findLeftMost = findLeftMost->right;
        }
        findLeftMost->right = ans;
        ans->left = findLeftMost;
        return ans;
    }
    void connect(Node* root){
        if(root == nullptr){
            return ;
        }
        if(root->left){
            Node* leftTemp = root->left;
            while(root->left->right){
                root->left = root->left->right;
            }
            connect(leftTemp);
            root->left->right = root;
        }
        if(root->right){
            Node* rightTemp = root->right;
            while(root->right->left){
                root->right = root->right->left;
            }
            connect(rightTemp);
            root->right->left = root;
        }
    }
};

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(5);
    Solution solution;
    root = solution.treeToDoublyList(root);
    Node* temp = root;
    while(temp->right != root){

        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << temp->val << endl;
    return 0;
}