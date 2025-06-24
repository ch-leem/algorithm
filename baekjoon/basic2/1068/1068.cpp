// 백준 1068 : 트리 (https://www.acmicpc.net/problem/1068)
#include <iostream>
#include <vector>
using namespace std;
int n, parents, target, cnt;
vector<int> adj[51], root;
int del[51], visited[51];

void off(int u){
    del[u] = 1;
    for(int v : adj[u]){
        if(del[v]) continue;
        off(v);
    }
    return;
}

void dfs(int u){
    visited[u] = 1;
    bool is_leaf = true;
    for(int v : adj[u]){
        if(visited[v] || del[v]) continue;
        dfs(v);
        is_leaf = false;
    }
    if(is_leaf) cnt++;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> parents;
        if(parents == -1){
            root.push_back(i);
            continue;
        }
        adj[parents].push_back(i);
    }
    cin >> target;
    off(target);
    for(int u : root){
        if(del[u]) continue;
        dfs(u);
    }

    cout << cnt << "\n";

    return 0;
}