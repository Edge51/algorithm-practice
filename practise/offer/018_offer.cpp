/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->val == val){
            return head->next;
        }
        ListNode* current = head;
        while (current && current->next){
            if(current->next->val == val){
                current->next = current->next->next;
                break;
            }
            current = current->next;
        }
        return head;
    }
};