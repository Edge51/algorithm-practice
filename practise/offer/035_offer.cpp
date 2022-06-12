#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
	// 优化成遍历,直接在每个节点后面复制一个中间节点，从中抽离出答案
	// 详情请查看官方答案
    Node* copyRandomList(Node* head) {
		if(head == nullptr){
            return nullptr;
        }
        Node* head_temp = head;
		while(head_temp != nullptr){
			Node* next_temp = head_temp->next;
			head_temp->next = new Node(head_temp->val);
			head_temp->next->next = next_temp;
			head_temp = next_temp;
		}
		head_temp = head;
		while(head_temp != nullptr){
			if(head_temp->random){
				head_temp->next->random = head_temp->random->next;
			}
			head_temp = head_temp->next->next;
		}
		head_temp = head;
		Node* new_head = head->next;
		while(head_temp->next->next != nullptr){
			Node* next_temp = head_temp->next->next;
			head_temp->next->next = next_temp->next;
            head_temp->next = next_temp;
			head_temp = next_temp;
		}
        head_temp->next = nullptr;
		return head->next;
	}

	// 递归
    Node* copyRandomListRecursive(Node* head) {
        Node* new_head;
        recursive(head, &new_head);
        return new_head;
    }
	// 递归简化版
	Node* copyRandomListSimplify(Node* head) {
		if(head == nullptr){
			return nullptr;
		}
		if(node_created.find(head) == node_created.end()){
			node_created[head] = new Node(head->val);
			node_created[head]->next = copyRandomList(head->next);
			node_created[head]->random = copyRandomList(head->random);
		}
		return node_created[head];
	}
private:
    unordered_map<Node*, Node*> node_created;
    void recursive(Node* head, Node** new_head){
        if(head == nullptr){
            *new_head = nullptr;
            return ;
        }
        *new_head = new Node(head->val);
        node_created[head] = *new_head;
        if(head->next != nullptr){
            if(head->next != nullptr && node_created.find(head->next) == node_created.end()){
                recursive(head->next, &((*new_head)->next));
            }else{
                (*new_head)->next = node_created[head->next];
            }
        }
        if(head->random != nullptr){
            if(node_created.find(head->random) == node_created.end()){
                recursive(head->random, &((*new_head)->random));
            }else{
                (*new_head)->random = node_created[head->random];
            }
        }
    }
};