// 백준 2589 : 보물섬 (https://www.acmicpc.net/problem/2589)
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
char a[54][54];
int visited[54][54];
int ret, max_ret, ny, nx, y, x, n, m;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int bfs(int i, int j){
    queue<pair<int, int>> q;
    fill(&visited[0][0], &visited[0][0] + 54*54, 0);

    q.push({i, j});
    visited[i][j] = 1;

    while(q.size()){
        tie(y, x) = q.front(); q.pop();

        for(int d=0; d<4; d++){
            ny = y + dy[d];
            nx = x + dx[d];
            if(ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx] != 0) continue;
            if(a[ny][nx] == 'W') continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    return visited[y][x];
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

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 'L'){
                ret = bfs(i, j);
                max_ret = max(max_ret, ret);
            }
        }
    }

    cout << max_ret-1 << "\n";

    return 0;
}