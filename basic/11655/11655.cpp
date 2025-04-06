#include <bits/stdc++.h>
using namespace std;

int small[26], large[26];
int idx;
string s, answer; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(int i=0; i<26; i++){
        small[i] = i+'a';
        large[i] = i+'A';
    }

    getline(cin, s);

    for(char c : s){
        if(find(small, small+26, c) != small + 26){
            idx = find(small, small+26, c) - small;
            idx += 13;
            if(idx >= 26) idx -= 26;
            answer += small[idx];
        }
        else if(find(large, large+26, c) != large + 26){
            idx = find(large, large+26, c) - large;
            idx += 13;
            if(idx >= 26) idx -= 26;
            answer += large[idx];
        }
        else answer += c;
    }

    cout << answer << "\n";
}