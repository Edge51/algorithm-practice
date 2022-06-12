#include <iostream>
#include <queue>
using namespace std;
// 剑指 Offer 13. 机器人的运动范围
// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
//  
// 示例 1：
// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 2：
// 输入：m = 3, n = 1, k = 0
// 输出：1
// 提示：
// 1 <= n,m <= 100
// 0 <= k <= 20
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int movingCount(int m, int n, int k) {
		if(k == 0){
			return 1;
		}
		int ans = 0;
        queue<pair<int, int>> node_q;
		vector<vector<bool>> visited(vector<vector<bool>>(m, vector<bool>(n, false)));

		vector<pair<int, int>> directions = {
			make_pair(-1, 0),
			make_pair(+1, 0),
			make_pair(0, -1),
			make_pair(0, +1)
		};

		ans++;
		visited[0][0] = true;
        node_q.push(make_pair(0, 0));
		while(node_q.empty() == false){
			pair<int, int> node = node_q.front();
			node_q.pop();
			for(auto direction:directions){
				int new_x = node.first + direction.first;
				int new_y = node.second + direction.second;
                if(new_x < 0 || new_y < 0 || new_x >= m || new_y >= n){
                    continue;
                }
				if(getSum(new_x) + getSum(new_y) <= k && visited[new_x][new_y] == false){
					ans++;
					visited[new_x][new_y] = true;
					node_q.push(make_pair(new_x, new_y));
				}
			}
		}
		return ans;
    }
	int getSum(int num){
		int sum = 0;
		while(num){
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};