# Algorithm notes

## Day 1
016_offer.cpp  
039_offer.cpp  
- -2147483648 of int
- 提前结束可以减少时间复杂度
- 投票法或者极限1换1法

## Day 2
012_offer.cpp
028_offer.cpp  
258_leetcode.  
- 3 steps of recursive design  
	1. parameters and return
	2. ending condition
	3. algorithm in single layer
- remember the dfs template

## Day 3
005_offer.cpp
010_offer.cpp
011_offer.cpp
018_offer.cpp
021_offer.cpp
022_offer.cpp
024_offer.cpp
026_offer.cpp
054_offer.cpp

## Day 4
082_leetcode.cpp
124_leetcode.cpp
025_offer.cpp
027_offer.cpp
029_offer.cpp
030_offer.cpp
032a_offer.cpp
032b_offer.cpp
033_offer.cpp
001_lc.cpp

- 链表中，如果头节点可能被删除或者修改，可以通过添加一个临时头节点来操作，最好再取临时头节点的下一个节点作为头节点，这样可以统一处理所有节点。

## Day 5
008_leetcode.cpp

## Day 6
557_leetcode.cpp
504_leetcode.cpp

## Day 7
084_leetcode.cpp
021_leetcode.cpp
0146_leetcode.cpp
0025_leetcode.cpp
042_offer.cpp

## Day 8
0003_leetcode.cpp
0014_leetcode.cpp

## Day 9
01_06_interview.cpp
0206_leetcode.cpp
0199_leetcode.cpp
0589_leetcode.cpp
034_offer.cpp
035_offer.cpp

## Day 10
0015_leetcode.cpp
0001_leetcode.cpp
0042_leetcode.cpp
0402_leetcode.cpp


- 实现链表的操作时还是多定义函数实现子功能比较好，否则指针的修改头大。
- 以及用伪头节点和伪尾节点可以简化程序。

## Sorting algorithm

### Bubble Sort
```
void bubbleSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(a[j] > a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
```
优化
```
void bubbleSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		bool sorted_flag = true;
		for(int j = 0; j < n - 1 - i; j++){
			if(a[j] > a[j + 1]){
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				sorted_flag = false;
			}
		}
		if(sorted_flag){
			break;// if in any loop the swap part is not invoked, the sortting is completed.
		}
	}
}
```

### Selection Sort
```
void selectionSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int min = i;
		for(int j = i; j < n; j++){
			if(a[j] > a[min]){
				min = j;
			}
		}
		if(min != j){
			swap(a[min], a[i]);
		}
	}
}
```

### Insertion Sort
```
void insertionSort(int a[], int n){
	for(int i = 1; i < n; i++){
		int key = a[i]
		int j = i - 1;
		while((j >= 0) && a[j] > key){
			a[j + 1] = a[j]
			j--;
		}
		a[j+1] = key;
	}
}
```

### Merge Sort
```

```