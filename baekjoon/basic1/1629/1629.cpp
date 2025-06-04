#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll solution(ll a, ll b){
    if (b==1) return a % c;
    ll ret = solution(a, b/2);
    ret = (ret * ret) % c;
    if (b%2) ret = (ret * a) % c;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b >> c;
    cout << solution(a, b) << "\n";
    return 0;
}