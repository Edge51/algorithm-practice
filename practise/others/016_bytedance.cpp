#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;


pair<int, int> searchParent(vector<int>& nodes, int i, int left_right);
pair<int, int> searchChild(vector<int>& nodes, int i);


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> nodes(n + 1);
    vector<int> mouse(m);
    for(int i = 0; i < n; i++){
        cin >> nodes[i + 1];
    }
    for(int i = 0; i < m; i++){
        cin >> mouse[i];
    }
    int count = 0;
    for(int i = 0; i < mouse.size(); i++){
        if(nodes[mouse[i]]){
            nodes[mouse[i]]--;
        }else{
            pair<int, int> parent_route = searchParent(nodes, mouse[i] / 2, (mouse[i] + 1) % 2);
            pair<int, int> left_child_route = searchChild(nodes, mouse[i] * 2);
            pair<int, int> right_child_route = searchChild(nodes, mouse[i] * 2 + 1);
            pair<int, int> choice = parent_route;
            if(left_child_route.first < parent_route.first){
                choice = left_child_route;
            }
            if(right_child_route.first < choice.first){
                choice = right_child_route;
            }
            if(choice.second == -1){
                cout << "error" << endl;
            }
            choice.first ++;
            nodes[choice.second]--;
            count += choice.first;
        }
    }
    cout << count << endl;
    return 0;
}

pair<int, int> searchParent(vector<int>& nodes, int i, int left_right){
    if(i <= 0){
        return {INT_MAX, -1};
    }
    if(nodes[i] > 0){
        return {0, i};
    }
    pair<int, int> other_child = searchChild(nodes, 2 * i + left_right);
    if(other_child.second != -1){
        other_child.first++;
    }
    pair<int, int> parent_route = searchParent(nodes, i / 2, (i + 1) % 2);
    if(parent_route.second != -1){
        parent_route.first++;
    }
    return other_child.first < parent_route.first ? other_child : parent_route;
}

pair<int, int> searchChild(vector<int>& nodes, int i){
    if(i > nodes.size()){
        return {INT_MAX, -1};
    }
    if(nodes[i] > 0){
        return {0, i};
    }
    pair<int, int> left = searchChild(nodes, 2 * i);
    if(left.second != -1){
        left.first++;
    }
    pair<int, int> right = searchChild(nodes, 2 * i + 1);
    if(right.second != -1){
        right.first++;
    }
    return left.first < right.first ? left : right;
}

/** 
 *
 */