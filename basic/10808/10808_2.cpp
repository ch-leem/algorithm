#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for(char i : s){
        cnt[i-'a']++;
    }

    for(int i : cnt) cout << i << " ";

    return 0;
}
