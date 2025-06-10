// 백준 3474 : 교수가 된 현우 (https://www.acmicpc.net/problem/3474)
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int t, a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> a;
        ll ret2 = 0, ret5 = 0;
        for(int i=2; i<=a; i*=2){
            ret2 += a / i;
        }
        for(int i=5; i<=a; i*=5){
            ret5 += a / i;
        }
        cout << min(ret2, ret5) << '\n';
    }
    return 0;
}