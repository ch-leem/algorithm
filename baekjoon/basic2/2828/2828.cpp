// 백준 2828 : 사과 담기 게임 (https://www.acmicpc.net/problem/2828)

#include <iostream>
using namespace std;
#define left aaa
#define right aaaa
int n, m, j, a, ret;
int left, right;
int pos[11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        pos[i] = 1;
    }
    left = 0;
    right = m-1;

    cin >> j;
    for(int i=0; i<j; i++){
        cin >> a;
        while(pos[a-1] != 1){
            if(a-1 > right){
                pos[left] = 0;
                left++;
                pos[right+1] = 1;
                right++;
            } 
            else{
                pos[right] = 0;
                right--;
                pos[left-1] =1;
                left--;
            } 
            ret++;
        } 
    }
    cout << ret << '\n';
    return 0;
}