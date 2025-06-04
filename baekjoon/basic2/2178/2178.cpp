// 백준 2178 : 미로 탐색 (https://www.acmicpc.net/problem/2178)

#include <iostream>
#include <queue>
using namespace std;

const int V = 100;
int a[V][V], visited[V][V];;
queue<pair<int, int>> q;
int n, m, ny, nx;
pair<int, int> front;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void bfs(){
    visited[0][0] = 1;
    q.push({0, 0});

    while (q.size()){
        front = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            ny = front.first + dy[i];
            nx = front.second + dx[i];
            if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if (visited[ny][nx] == 0 && a[ny][nx] == 1){
                q.push({ny, nx});
                visited[ny][nx] = visited[front.first][front.second] + 1;
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    string line;
    for(int i=0; i<n; i++){
        cin >> line;
        for(int j=0; j<m; j++){
            a[i][j] = line[j] - '0';
        }
    }
    bfs();
    cout << visited[n-1][m-1] << "\n";
    return 0;

}