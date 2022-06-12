#include <iostream>
#include <random>
#include <typeinfo>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* ans = new ListNode(0);
		ListNode* temp = ans;
		int carry = 0;
		int n;
		while(l1 && l2){
			n = (l1->val + l2->val + carry) % 10;
			carry = (l1->val + l2->val + carry) / 10;
			temp->next = new ListNode(n);
			temp = temp->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1){
			n = (l1->val + carry) % 10;
			carry = (l1->val + carry) / 10;
			temp->next = new ListNode(n);
			temp = temp->next;
			l1 = l1->next;
		}
		while(l2){
			n = (l2->val + carry) % 10;
			carry = (l2->val + carry) / 10;
			temp->next = new ListNode(n);
			temp = temp->next;
			l2 = l2->next;
		}
		if(carry){
			temp->next = new ListNode(carry);
		}
		temp = ans;
		ans = ans->next;
		return ans;
    }
};

int addWithList(int num1, int num2){
	ListNode* listNum1 = new ListNode(0);
	ListNode* temp =  listNum1;
	while(num1){
		temp->next = new ListNode(num1 % 10);
		temp = temp->next;
		num1 /= 10;
	}
	temp = listNum1;
	listNum1 = listNum1->next;
	delete temp;

	ListNode* listNum2 = new ListNode(0);
	while(num2){
		temp->next = new ListNode(num2 % 10);
		temp = temp->next;
		num2 /= 10;
	}
	temp = listNum2;
	listNum2 = listNum2->next;
	delete temp;

	Solution solution;
	ListNode* res = solution.addTwoNumbers(listNum1, listNum2);
	int ans = 0;
	int ten = 1;
	while(res){
		ans += res->val * ten;
		ten *= 10;
		res = res->next;
	}

	return ans;
}

int main(int argc, char* argv[]){
	// cout << "argc is : " << argc << endl;
	// for(int i = 0; i < argc; i++){
	// 	cout << argv[i] << " ";
	// }
	// cout << endl;
	if(argc != 2){
		cout << "error command!" << endl;
		cout << "example: add 100" << endl;
		cout << "which means run the program with 100 random test cases" << endl;
		return 0;
	}
	int n = atoi(argv[1]);
	// cout << "n is : " << n << endl;
	// if(typeid(n) == typeid(int)){
	// 	cout << "type of n is int." << endl;
	// }
	random_device rand;
	int count = 0;
	for(int i = 0; i < n; i++){
		int num1 = rand() % 100000;
		int num2 = rand() % 100000;
		int num3 = addWithList(num1, num2);
		if(num3 == num1 + num2){
			count++;
		}else{
			cout << "Error!" << endl;
			cout << num3 << " does not equals to " << num1 << " + " << num2 << endl;
		}
	}
	cout << "True for " << count << " tests!" << endl;
	return 0;
}