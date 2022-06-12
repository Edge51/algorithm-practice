/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

	// 分清楚部分来写比较清晰：反转部分的前一个节点、反转部分、反转部分的下一个节点。
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* k_former;
		ListNode* dummy_head = new ListNode(0, head);
		ListNode* pre = dummy_head;
		ListNode* cur = head;
		ListNode* next = head->next;
        ListNode* new_tail = head;
        ListNode* k_latter = dummy_head;
		while(cur != nullptr){
            k_former = cur;
			int count = 0;
			while(count < k && k_former != nullptr){
				k_former = k_former->next;
                count++;
			}
			if(count < k){
				break;
			}
			else{
				pre = k_former;
				for(int i = 0; i < k; i++){
					cur->next = pre;
					pre = cur;
					cur = next;
                    if(next != nullptr){
                        next = next->next;
                    }
				}
				k_latter->next = pre;
                k_latter = new_tail;
                new_tail = cur;
			}
		}
		head = dummy_head->next;
		delete dummy_head;
		return head;
    }
};