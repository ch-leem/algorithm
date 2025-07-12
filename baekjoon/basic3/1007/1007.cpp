// 백준 1007 : 벡터 매칭 (https://www.acmicpc.net/problem/1007)

#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
int t, n, x, y;
long long tx, ty;
double min_ret;
vector<pair<int, int>> v;

void go(int idx, int cnt, long long sx, long long sy){

    if(cnt == n/2){
        long long ox = tx - sx;
        long long oy = ty - sy;
        min_ret = min(min_ret, sqrt((sx-ox)*(sx-ox) + (sy-oy)*(sy-oy)));
        return; 
    }

    if(idx == n) return;

    go(idx+1, cnt+1, sx+v[idx].first, sy+v[idx].second);
    go(idx+1, cnt, sx, sy);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--){
        v.clear();
        cin >> n;

        tx = 0;
        ty = 0;
        for(int i=0; i<n; i++){
            cin >> x >> y;
            tx += x;
            ty += y;
            v.push_back({x, y});
        }

        min_ret = 1e100;

        go(0, 0, 0, 0);
        cout << fixed << setprecision(12) << min_ret << "\n";
    }

    return 0;
}
