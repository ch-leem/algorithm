// 백준 1012 : 유기농 배추 (https://www.acmicpc.net/problem/1012)
#include <iostream>
using namespace std;
int T, m, n, k, x, y, ny, nx;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
const int N = 50;
const int M = 50;
int mp[N][M], visited[N][M];

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if (mp[ny][nx] == 1 && visited[ny][nx] == 0){
            dfs(ny, nx);
        } 
    }
    return; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> m >> n >> k;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for(int i=0; i<k; i++){
            cin >> x >> y;
            mp[y][x] = 1;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (mp[i][j] == 1 && visited[i][j] == 0){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";

    }
    return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;
const int max_n = 51;
int a[max_n][max_n], visited[max_n][max_n];
int t, m, n, k, ret;
int x, y, ny, nx;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void dfs(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if(!visited[ny][nx] && a[ny][nx] == 1){
            dfs(ny, nx);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        ret = 0;
        fill(&a[0][0], &a[0][0] + max_n * max_n, 0);
        fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
        cin >> m >> n >> k;
        while(k--){
            cin >> x >> y;
            a[y][x] = 1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }

    return 0;
}
*/