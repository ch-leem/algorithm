// 백준 1436 : 영화감독 숌 (https://www.acmicpc.net/problem/1436)
#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int i = 666;
    int cnt = 0;
    for(;; i++){
        if(to_string(i).find("666") != string::npos) cnt++;
        if(cnt == n) break;
    }
    cout << i << "\n";

    return 0;
}