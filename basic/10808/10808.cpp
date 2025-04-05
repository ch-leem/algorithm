#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;
string alph;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    alph = "abcdefghijklmnopqrstuvwxyz";
    for(char i : alph) mp[char(i)] = 0;

    cin >> s;
    for(char i : s) mp[i] += 1;

    for(auto i : mp) cout << i.second << " ";

    return 0;
}
