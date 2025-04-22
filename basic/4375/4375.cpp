#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (scanf("%d", &n) != EOF){
        int mod = 1 % n;
        int cnt = 1;
        while (mod != 0) {
            mod = (mod * 10 + 1) % n;
            cnt ++;    
        }
        cout << cnt << "\n";
    } 
    return 0;
}