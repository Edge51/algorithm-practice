/**
 * 做的时候不知道他意思是还能用stl里的stack实现，所以用了局部变量数组来实现。
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : data({}), index_top(0) {}
    
    void push(int x) {
		data[index_top] = x;
		index_top++;
		if(index_top == 1){
			data_min[0] = x;
		}else{
			if(data_min[index_top - 2] < x){
				data_min[index_top - 1] = data_min[index_top - 2];
			}
			else{
				data_min[index_top - 1] = x;
			}
		}
    }
    
    void pop() {
		if(index_top > 0){
			index_top--;
		}
    }
    
    int top() {
		return data[index_top - 1];
    }
    
    int min() {
		return data_min[index_top - 1];
    }
private:
	int data[20000];
	int data_min[20000];
	int index_top;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */