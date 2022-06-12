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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* post = head->next;
        while(post != nullptr){
            cur->next = pre;
            pre = cur;
            cur = post;
            post = cur->next;
        }
        cur->next = pre;
        return cur;
    }
};