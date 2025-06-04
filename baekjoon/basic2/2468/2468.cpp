#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, ny, nx;
const int N = 100;

int visited[N][N];
int a[N][N];
int mp[N][N];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void go(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
        if (a[ny][nx] == 1 && visited[ny][nx] == 0) go(ny, nx);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int h = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mp[i][j];
            h = max(h, mp[i][j]);
        }
    }
    int ret = 0;
    for(int i=0; i<h; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                visited[j][k] = 0;
                if (mp[j][k] <= i) a[j][k] = 0;
                else a[j][k] = 1;    
            }
        }
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if (a[j][k] == 1 && visited[j][k] == 0){
                    go(j, k);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }

    cout << ret << "\n";
    
    return 0;
} 