// 백준 1992 : 쿼드트리 (https://www.acmicpc.net/problem/1992)

#include <stdio.h>
#include <string>
using namespace std;
int a[65][65];
string ret;
int n;

string go(int y, int x, int n){
    string ret = "";

    if(n==1){
        ret += to_string(a[y][x]);
        return ret;
    } 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[y+i][x+j] != a[y][x]){
                ret += ("("+go(y, x, n/2) + go(y, x+n/2, n/2) + go(y+n/2, x, n/2) + go(y+n/2, x+n/2, n/2)+")");
                return ret;
            } 
        }
    }
    ret += to_string(a[y][x]);
    return ret;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    ret = go(0, 0, n);
    printf("%s\n", ret.c_str());
    return 0;
}