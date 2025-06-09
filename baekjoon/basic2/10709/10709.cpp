// 백준 10709 : 기상캐스터 (https://www.acmicpc.net/problem/10709)
#include <iostream>
#include <algorithm>
using namespace std;
int h, w;
char a[101][101]; 
int ret[101][101];

void go(int y, int x, int min){
    ret[y][x] = min;
    if(x == w-1) return;
    go(y, x+1, min+1);
}   

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(&ret[0][0], &ret[0][0] + 101*101, -1);
    
    cin >> h >> w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i][j] == 'c') go(i, j, 0);
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}