// 백준 2363 : 치즈 (https://www.acmicpc.net/problem/2636)
#include <iostream>
#include <algorithm>
using namespace std;
int a[104][104], out_visited[104][104], visited[104][104];
int n, m, ny, nx, cnt;
const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};

void out(int y, int x, int hour){
    out_visited[y][x] = 1; // 방문 처리
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= m || nx < 0 || out_visited[ny][nx] == 1) continue;
        if(a[ny][nx] == 1 && visited[ny][nx] == 0){ // 외곽과 연결되어 있는 치즈고 방문된 적 없으면 
            visited[ny][nx] = hour + 1; // visited에 녹는 시간 표시 (h+1)
            cnt++; // (h+1) 시간에 녹는 치즈 갯수 카운트    
        }
        if(a[ny][nx] == 0) out(ny, nx, hour); // 0이면 치즈 만날때 까지 외곽 탐색
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    int h = 0; // 현재 시간
    for(;; h++){
        cnt = 0; // 한 시간 후(h+1) 사라질 치즈 수 초기화
        bool check = true; // 종료 조건 a에 1이 없으면 break
        fill(&out_visited[0][0], &out_visited[0][0] + 104*104, 0); // 외곽 탐색 dfs visited 초기화
        out(0, 0, h); // 외곽 찾기 

        // 한 시간 후(h+1)
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1 && visited[i][j] == h+1) a[i][j] = 0; // 치즈가 있고 녹는 시간이 h+1 맞으면 없애기
                if(a[i][j] == 1) check = false; // 전체 중 안 녹은 치즈가 있으면 다음 시간 탐색 bool
            }
        }
        if(check) break; // 치즈 없으면 break 
    }
    cout << h+1 << "\n"; // 치즈가 다 녹은 시간
    cout << cnt << "\n"; // 마지막 치즈 갯수
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[104][104], visited[104][104];
int n, m, ny, nx, cnt, h;
vector<pair<int, int>> v;
const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};

void out(int y, int x){
    visited[y][x] = 1;
    if(a[y][x] == 1){
        v.push_back({y, x});
        return;
    }
    
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx]) continue;
        out(ny, nx);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    
    while(true){ 
        bool flag = true;
        v.clear(); 
        fill(&visited[0][0], &visited[0][0] + 104*104, 0); 
        out(0, 0);
        cnt = v.size();

        h++;
        for(pair<int, int> p : v){
            a[p.first][p.second] = 0;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1) flag = false; 
            }
        }
        if(flag) break; 
    }
    cout << h << "\n" << cnt << "\n"; 
    return 0;
}
*/