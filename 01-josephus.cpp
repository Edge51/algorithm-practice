#include <iostream>
using namespace std;

struct Node{
	int id;
	Node* next_node;
	Node(int n = 0, Node* next = nullptr){
		id = n;
		next_node = next;
	}
};

Node* generateLinkedList(int n);
void deleteNodes(Node* start, int m);

int main(){
	int n;
	cout << "Please input n:" << endl;
	cin >> n;
	Node* start = generateLinkedList(n);

	int m;
	cout << "Please input m:" << endl;
	cin >> m;
	int s;
	cout << "Please input s:" << endl;
	cin >> s;
	for( int i = 0; i < s - 1; i++){
		start = start->next_node;
	}
	cout << "The permutation is:" << endl;
	deleteNodes(start, m);
	return 0;
}

Node* generateLinkedList(int n){
	if(n == 0){
		return nullptr;
	}
	// 表头start
	Node* start = new Node(1, nullptr);
	// 用new_node指向表尾来插入新的结点
	Node* new_node = start;
	for(int i = 1; i < n; i++){
		new_node->next_node = new Node(i+1, nullptr);
		new_node = new_node->next_node;
	}
	// 令表尾的下一结点为表头从而形成环
	new_node->next_node = start;
	return start;
}

void deleteNodes(Node* start, int m){
	// 两个指针分别指向当前结点和上一结点
	Node* former_node = start;
	Node* current_node = start;
	// 当结点的下一结点为自身时，说明只剩下最后一个结点，
	// 也就是意味着循环的结束
	while(current_node->next_node != current_node){
		// 通过for循环跳过m-1个结点到达第m个结点
		for(int i = 0; i < m - 1; i++){
			// 通过if判断确保former_node指向current_node的上一结点
			if(current_node != former_node){
				former_node = former_node->next_node;
			}
			current_node = current_node->next_node;
		}
		// 上一结点的下一结点指向当前结点的下一结点，
		// 从而将当前结点从链表中分离
		former_node->next_node = current_node->next_node;
		cout << current_node->id << endl;
		// temp记录当前结点以便清理动态内存块
		Node* temp = current_node;
		current_node = current_node->next_node;
		// 如果删除的是表头，需要将start指向表头的下一个结点
		if(temp == start){
			start = current_node;
		}
		delete temp;
	}
	cout << current_node->id << endl;
	delete current_node;
	return ;
}
