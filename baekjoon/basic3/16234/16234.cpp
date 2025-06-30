// 백준 16234 : 인구 이동 (https://www.acmicpc.net/problem/16234)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n, l, r, ret, ny, nx, sum;
bool flag;
vector<pair<int, int>> v;
int a[54][54], visited[54][54];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void dfs(int y, int x){
    sum += a[y][x];

    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= n || nx < 0 || visited[ny][nx]) continue;
        if(abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r){
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            dfs(ny, nx);
        }
    }
    return;
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

    int day = 0;
    while (true){
        flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v.clear();

                sum = 0;
                if(visited[i][j]) continue;
                v.push_back({i, j});
                visited[i][j] = 1;
                dfs(i, j);
                if (v.size() == 1) continue;

                for(pair<int, int> p : v){
                    a[p.first][p.second] = sum / v.size();
                    flag = 1;
                }
            }
        }
        if(!flag) break;    
        day++;
    }
    
    cout << day << "\n";
    
    return 0;
}