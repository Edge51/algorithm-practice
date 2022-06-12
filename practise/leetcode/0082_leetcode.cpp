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
    ListNode* deleteDuplicates(ListNode* head) {
		if(head == nullptr || head->next == nullptr){
			return head;
		}
		ListNode* temp = new ListNode(-200, head);
		ListNode* latter = temp;
		while(latter){
			ListNode* former = latter->next;
			if(former == nullptr){
				break;
			}
			int value = former->val;
			if(former->next == nullptr){
				break;
			}else if(former->next->val != value){
				latter = former;
			}else{
				while(former->next && former->next->val == value){
					former = former->next;
				}
				latter->next = former->next;
			}
		}
		head = temp->next;
		delete temp;
		return head;
    }

	ListNode* deleteDuplicates(ListNode* head){
		if(head == nullptr){
			return head;
		}
		ListNode* dummy = new ListNode(-111, head);
		ListNode* cur = dummy;
		while(cur->next && cur->next->next){
			if(cur->next->val == cur->next->next->val){
				int x = cur->next->val;
				while (cur->next && cur->next->next->val == x){
					cur->next = cur->next->next;
				}
			}
			else{
				cur = cur->next;
			}
		}
		head = dummy->next;
		delete dummy;
		return head;
	}
};