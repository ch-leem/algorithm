// 백준 14502 : 연구소 (https://www.acmicpc.net/problem/14502)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a[10][10], visited[10][10], max_area, ny, nx;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
vector<pair<int, int>> v;

void wall(int i, int j, int k, int w){
    a[v[i].first][v[i].second] = w;
    a[v[j].first][v[j].second] = w;
    a[v[k].first][v[k].second] = w;
}

void spread(int y, int x){
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if(visited[ny][nx] == 0 && a[ny][nx] == 0) spread(ny, nx);
    }
}

int go(int y, int x){
    int ret = 1;
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
        if(visited[ny][nx] == 0 && a[ny][nx] == 0) ret += go(ny, nx);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) v.push_back({i, j});
        }
    }

    for(int i=0; i<v.size(); i++){
        for(int j=0; j<i; j++){
            for(int k=0; k<j; k++){
                wall(i, j, k, 1);
                fill(&visited[0][0], &visited[0][0] + 100, 0);
                int area = 0;

                for(int y=0; y<n; y++){
                    for(int x=0; x<m; x++){
                        if(a[y][x] == 2) spread(y, x);
                    }
                }

                for(int y=0; y<n; y++){
                    for(int x=0; x<m; x++){
                        if(visited[y][x] == 0 && a[y][x] == 0) area += go(y, x);
                    }
                }

                wall(i, j, k, 0);
                max_area = max(max_area, area);
            }
        }
    }
    cout << max_area << "\n";
    return 0;
}