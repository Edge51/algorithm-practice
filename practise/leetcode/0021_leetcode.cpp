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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
		ListNode* head = res;
		while(l1 && l2){
			if(l1->val < l2->val){
				res->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else{
				res->next = new ListNode(l2->val);
				l2 = l2->next;
			}
			res = res->next;
		}
		while(l1){
			res->next = new ListNode(l1->val);
			res = res->next;
			l1 = l1->next;
		}
		while(l2){
			res->next = new ListNode(l2->val);
			res = res->next;
			l2 = l2->next;
		}
		res = head; // res 临时用来指向虚假头节点，并将其delete
		head = head->next;
		delete res;
		return head;
    }
};