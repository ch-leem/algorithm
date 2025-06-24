// 백준 1325 : 효율적인 해킹 (https://www.acmicpc.net/problem/1325)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, max_ret, ret;
vector<int> adj[10004], result;
int visited[10004];

int dfs(int u){
    visited[u] = 1;
    int ret = 1;
    for(int v : adj[u]){
        if(visited[v]) continue;
        ret += dfs(v);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;  
        adj[b].push_back(a);
    }
    for(int i=1; i<n+1; i++){
        fill(visited, visited + 10004, 0);
        ret = dfs(i);
        if(ret > max_ret){
            max_ret = ret;
            result.clear();
            result.push_back(i);
        }
        else if(ret == max_ret) result.push_back(i);
    }
    for(int i : result) cout << i << " ";
    cout << "\n";
    
    return 0;
}