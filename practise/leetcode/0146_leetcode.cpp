#include <unordered_map>
#include <deque>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
		if(cache.find(key) != cache.end()){
			DoubleLinkedListNode* item = cache[key];
            if(item != head){
			    item->preNode->nextNode = item->nextNode;
                if(item->nextNode != nullptr){
                    item->nextNode->preNode = item->preNode;
                }
                else{
                    tail = item->preNode;
                }
			    item->nextNode = head;
                item->nextNode->preNode = item;
			    head = item;
            }
			return head->val;
		}else{
			return -1;
		}
    }
    
    void put(int key, int value) {
		if(cache.find(key) != cache.end()){
			cache[key]->val = value;
            if(cache[key] != head){
                cache[key]->preNode->nextNode = cache[key]->nextNode;
                if(cache[key]->nextNode != nullptr){
                    cache[key]->nextNode->preNode = cache[key]->preNode;
                }
                else{
                    tail = cache[key]->preNode;
                }
                cache[key]->nextNode = head;
                cache[key]->nextNode->preNode = cache[key];
                head = cache[key];
            }
		}
		else{
			head = new DoubleLinkedListNode(key, value, nullptr, head);
            if(head->nextNode != nullptr){
                head->nextNode->preNode = head;
            }
            else{
                tail = head;
            }
            cache[key] = head;
			if(capacity <= 0){
				DoubleLinkedListNode* temp = tail;
				cache.erase(tail->key);
				tail = tail->preNode;
				tail->nextNode = nullptr;
				delete temp;
			}
			else{
				capacity--;
			}
		}
    }
private:
	struct DoubleLinkedListNode{
		int key;
		int val;
		DoubleLinkedListNode* preNode;
		DoubleLinkedListNode* nextNode;
		DoubleLinkedListNode(int key, int val, DoubleLinkedListNode* preNode = nullptr, DoubleLinkedListNode* nextNode = nullptr) : key(key), val(val), preNode(preNode), nextNode(nextNode) {}
		DoubleLinkedListNode() : key(0), val(0), preNode(nullptr), nextNode(nullptr) {}
	};

	int capacity;
	unordered_map<int, DoubleLinkedListNode*> cache;
	DoubleLinkedListNode* head;
	DoubleLinkedListNode* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */