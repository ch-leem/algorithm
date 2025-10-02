// 백준 13913 : 숨바꼭질 4 (https://www.acmicpc.net/problem/13913)
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000;
int visited[MAX + 4];
int parent[MAX + 4];

int n, k;

int main(){

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    parent[n] = -1;
    visited[n] = 1;

    while(!q.empty()){

        int cur = q.front(); q.pop();

        if(cur == k){
            vector<int> path;

            for(int i = cur; i != -1; i = parent[i]){
                path.push_back(i);
            }

            reverse(path.begin(), path.end());

            cout << visited[cur] - 1 << "\n";
            for(auto i : path) cout << i << " ";
        }

        for(int next : {cur - 1, cur + 1, cur * 2}){
            if(next < 0 || next > MAX) continue;
            if(visited[next]) continue;

            visited[next] = visited[cur] + 1;
            parent[next] = cur;
            q.push(next);
        }

    }

    return 0;
}