// 백준 16234 : 인구 이동 (https://www.acmicpc.net/problem/16234)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

#define move chanhyeok

int n, l, r, ny, nx, person, cnt_person, cnt_kan, group;
int a[54][54], visited[54][54];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
bool move;
vector<pair<int, int>> adj[54][54];
vector<int> ret_person;

void go(int y, int x){

    for(int d=0; d<4; d++){
        ny = y + dy[d];
        nx = x + dx[d];
        if(ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if(abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r){
            adj[y][x].push_back({ny, nx});
            move = true;
        }
    }
    return;
}

pair<int, int> dfs(int y, int x, int group){
    visited[y][x] = group;
    pair<int, int> ret = {a[y][x], 1};

    for(pair<int, int> v : adj[y][x]){
        ny = v.first;
        nx = v.second;
        if(visited[ny][nx] != 0) continue;
        
        pair<int, int> ret2 = dfs(ny, nx, group);

        ret.first += ret2.first;
        ret.second += ret2.second;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    
    int ret = 0;
    for(;; ret++){
        move = false;
        
        // 국경선 초기화, 연합 해체
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j].clear();
            }
        }
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
    
        // make adj : 국경선 open
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                go(i, j);
            }
        }

        // 연합의 인구수, 칸의 갯수
        group = 1;
        ret_person.clear();
        ret_person.push_back(-1);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] != 0) continue;
                tie(cnt_person, cnt_kan) = dfs(i, j, group);
                person = cnt_person / cnt_kan;
                ret_person.push_back(person);
                group++;
            }
        }

        // 인구 이동
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0) continue;
                a[i][j] = ret_person[visited[i][j]];
            }
        }

        if(!move) break;

    }
    cout << ret << "\n";
    return 0;
}