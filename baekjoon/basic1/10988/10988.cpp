#include <bits/stdc++.h>
using namespace std;

string tmp, word, rev_word;
int answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> tmp;
    word = tmp;
    reverse(tmp.begin(), tmp.end());
    rev_word = tmp;
    
    if(word == rev_word) answer=1;
    else answer=0;

    cout << answer << "\n";
}