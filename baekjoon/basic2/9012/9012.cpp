// 백준 9012 : 괄호 (https://www.acmicpc.net/problem/9012)
#include <iostream>
#include <stack>
using namespace std;
int tc;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> tc;
    while(tc--){
        stack<char> stk;
        cin >> s;
        stk.push(s[0]);
        for(int i=1; i<s.size(); i++){
            if(stk.size() && stk.top() == '(' && s[i] == ')') stk.pop();
            else stk.push(s[i]);
        }
        if(stk.size()) cout << "NO\n";
        else cout << "YES\n";
    }
    
    return 0;
}