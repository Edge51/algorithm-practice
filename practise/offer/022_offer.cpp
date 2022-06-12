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
    ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* front = head;
		ListNode* back = head;
		while(k--){
			front = front->next;
		}
		while(front){
			front = front->next;
			back = back->next;
		}
		return back;
    }
};