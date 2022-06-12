#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// 658. 找到 K 个最接近的元素
// 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
// 整数 a 比整数 b 更接近 x 需要满足：
// |a - x| < |b - x| 或者
// |a - x| == |b - x| 且 a < b
// 示例 1：
// 输入：arr = [1,2,3,4,5], k = 4, x = 3
// 输出：[1,2,3,4]
// 示例 2：
// 输入：arr = [1,2,3,4,5], k = 4, x = -1
// 输出：[1,2,3,4]
// 提示：
// 1 <= k <= arr.length
// 1 <= arr.length <= 104
// arr 按 升序 排列
// -104 <= arr[i], x <= 104
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/find-k-closest-elements
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int left = 0;
		// we locate the left border of the answer,
		// so here we can just search [0, arr.size() - k)
		int right = arr.size() - k;
		while(left < right){
			int mid = left + (right - left) / 2;
			// Notice the condition below, comparing arr[mid] and arr[mid + k],
			// we can tell whether [mid, mid + k - 1] or [mid + 1, mid + k] is better,
			// thus determine mid is less or more for left border.
			if(x - arr[mid] > arr[mid + k] - x){
				left = mid + 1;
			}else if(x - arr[mid] <= arr[mid + k] - x){
				right = mid;
			}
		}
		return vector<int>(arr.begin() + left, arr.begin() + left + k);
	}

	// binarySearch for the nearest entry for x
	// double pointers to explore nearest entry arround x
    vector<int> findClosestElements1(vector<int>& arr, int k, int x) {
		//binary search for the nearest entry for x.
		int left = 0, right = arr.size() - 1;
		int nearest_index = -1;
		while(left <= right){
			int mid = left + (right - left) / 2;
			if(arr[mid] < x){
				left = mid + 1;
			}else if(arr[mid] > x){
				right = mid - 1;
			}else if(arr[mid] == x){
				nearest_index = mid;
				break;
			}
		}
		// After the search the x may be found or not found.
		// If x is not found in arr, then we should test the left and right
		// so that we know that whether the nearest position is at the border
		// of the array. Once the position is at the border, we could just 
		// return the k entries at the border as answer. Otherwise we compare
		// arr[left] and arr[right] to locate the nearest position.
		if(nearest_index == -1){
			if(right >= 0 && left < arr.size()){
				// compare arr[left] and arr[right] to locate postion
				if(x - arr[right] <= arr[left] - x){
					nearest_index = right;
				}else{
					nearest_index = left;
				}
			}else if(right < 0){ // first k entries is the answer
				return vector<int>(arr.begin(), arr.begin() + k);
			}else if(left >= arr.size()){ // last k entries is the answer
				return vector<int>(arr.end() - k, arr.end());
			}
		}
		// initialize with the nearest one.
		int count = 1;
		deque<int> dq;
		dq.push_back(arr[nearest_index]);
		// use double pointers to compare and explore
		int i = nearest_index - 1, j = nearest_index + 1;
		while(count < k){
			if(i >= 0 && j < arr.size()){
				if(x - arr[i] <= arr[j] - x){
					dq.push_front(arr[i]);
					i--;
				}else{
					dq.push_back(arr[j]);
					j++;
				}
			}else if(i < 0 && j < arr.size()){
				dq.push_back(arr[j]);
				j++;
			}else if(i >= 0 && j >= arr.size()){
				dq.push_front(arr[i]);
				i--;
			}else if(i < 0  && j >= arr.size()){
				cout << "error" << endl;
			}
			count++; // I usually forget to increment the while condition TAT
		}
		return vector<int>(dq.begin(), dq.end());
    }
};

int main(){
	vector<int> input = {1,2,3,4,5};
	Solution solution;
	vector<int> ans1 = solution.findClosestElements(input, 4, 3);
	for(int num : ans1){
		cout << num << " ";
	}
	cout << endl;
	vector<int> ans2 = solution.findClosestElements(input, 4, -1);
	for(int num : ans2){
		cout << num << " ";
	}
	cout << endl;
	return 0;
}