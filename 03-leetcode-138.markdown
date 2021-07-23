Leetcode 138. Copy List with Random Pointer
-------------------------------------------

[problem description](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

solution
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> record;
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        if(record.count(head) == 0){
            Node* newNode = new Node(head->val);
            record[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return record[head];
    }
};
```