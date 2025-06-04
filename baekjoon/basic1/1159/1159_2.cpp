#include <bits/stdc++.h>
using namespace std;

int n, cnt[26];
string name, answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name;
        cnt[name[0] - 'a'] += 1;
    }

    for(int i=0; i<26; i++){
        if(cnt[i] >= 5) answer += i + 'a';    
    }

    if(answer.size()) cout << answer << "\n";
    else cout << "PREDAJA" << "\n";
}