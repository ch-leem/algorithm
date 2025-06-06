// 백준 2828 : 사과 담기 게임 (https://www.acmicpc.net/problem/2828)

#include <iostream>
using namespace std;
int n, m, l, r, j, tmp, ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    l = 1;
    cin >> j; 
    for(int i=0; i<j; i++){
        cin >> tmp;
        r = l+m-1;
        if(l<=tmp && tmp<=r) continue;
        else{
            if(l > tmp){
                ret += (l-tmp);
                l -= (l-tmp);
            }
            else{
                ret += (tmp-r);
                l += (tmp-r);
            }
        }
    }
    cout << ret << '\n';

    return 0;
}