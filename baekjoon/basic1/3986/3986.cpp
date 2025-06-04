#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        stack<char> str;
        for (char c : s){
            if (str.size() && str.top() == c) str.pop();
            else str.push(c);
        }
        if (str.size() == 0) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}