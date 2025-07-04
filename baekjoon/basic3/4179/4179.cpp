// 백준 4179 : 불! (https://www.acmicpc.net/problem/4179)
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int r, c, ny, nx, fny, fnx, ret;
pair<int, int> start;
char a[1004][1004];
int visited[1004][1004]; 
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
vector<pair<int, int>> init_fire;

vector<pair<int, int>> fire(vector<pair<int, int>> nf){
    int y, x;
    vector<pair<int, int>> fire_list;
    for(pair<int, int> f : nf){
        tie(y, x) = f;
        for(int i=0; i<4; i++){
            fny = y + dy[i];
            fnx = x + dx[i];
            if(fny >= r || fny < 0 || fnx >= c || fnx < 0 || a[fny][fnx] != '.') continue;
            a[fny][fnx] = 'F';
            fire_list.push_back({fny, fnx});
        }
    }
    return fire_list;
}

int go(int sy, int sx){
    visited[sy][sx] = 1;
    queue<pair<int, int>> q; 
    q.push({sy, sx});

    queue<vector<pair<int, int>>> qfire;
    vector<pair<int, int>> nf;
    qfire.push(init_fire);

    int y, x;
    int cnt = 1;
    int ret = -1;
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop();

        if(y == r-1 || y == 0 || x == c-1 || x == 0){
            ret = visited[y][x];
            break;
        }

        if(visited[y][x] == cnt){
            nf = qfire.front(); qfire.pop();
            qfire.push(fire(nf));
            cnt++;
        }
        
        for(int i=0; i<4; i++){
            ny = y + dy[i];
            nx = x + dx[i]; 
            if(ny >= r || ny < 0 || nx >= c || nx < 0 || visited[ny][nx]) continue;
            if(a[ny][nx] != '.') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J') start = {i, j};
            if(a[i][j] == 'F') init_fire.push_back({i, j});
        }
    }

    ret = go(start.first, start.second);
    if(ret == -1) cout << "IMPOSSIBLE\n";
    else cout << ret << "\n";

    return 0;
}