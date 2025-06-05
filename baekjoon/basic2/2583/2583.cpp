// 백준 2583 : 영역 구하기 (https://www.acmicpc.net/problem/2583)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int V = 100;
int mp[V][V];
int visited[V][V];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int m, n, k, ny, nx, a, b, c, d;

int dfs(int y, int x){
    visited[y][x] = 1;
    int ret_cnt = 1;
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny >= m || ny <0 || nx >= n || nx < 0) continue;
        if (visited[ny][nx] == 0 && mp[ny][nx] == 0){
            ret_cnt += dfs(ny, nx);
        }
    }
    return ret_cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int u=0; u<k; u++){
        cin >> a >> b >> c >> d;
        for(int i=b; i<d; i++){
            for(int j=a; j<c; j++){
                mp[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    int ret = 0;
    vector<int> area;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if (visited[i][j] == 0 && mp[i][j] == 0){
                ret = dfs(i, j);
                area.push_back(ret);
                cnt++;
            }
        }
    }
    sort(area.begin(), area.end());
    cout << cnt << "\n";
    for(int r : area){
        cout << r << ' ';
    }
    cout << "\n";
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
#define y1 aaa
using namespace std;
const int mx = 101;
int a[mx][mx], visited[mx][mx];
int m, n, k, x1, x2, y1, y2, ny, nx;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
vector<int> ret;

int dfs(int y, int x){
    visited[y][x] = 1;
    int ret = 1;
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny>=m || ny<0 || nx>=n || nx<0) continue;
        if(!visited[ny][nx] && a[ny][nx] != 1){
            ret += dfs(ny, nx);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y=y1; y<y2; y++){
            for(int x=x1; x<x2; x++){
                a[y][x] = 1;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && a[i][j] != 1){
                ret.push_back(dfs(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for(int result : ret) cout << result << ' ';
    cout << "\n";

    return 0;
}
*/