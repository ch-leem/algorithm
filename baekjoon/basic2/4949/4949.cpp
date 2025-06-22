// 백준 4949 : 균형잡힌 세상 (https://www.acmicpc.net/problem/4949)
#include <iostream>
#include <stack>
using namespace std;
string s;

bool check(string s){
    stack<char> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '[') stk.push(s[i]);
        else if(s[i] == ')'){
            if(stk.empty()) return false;
            else if(stk.top() != '(') return false;
            else stk.pop();
        }
        else if(s[i] == ']'){
            if(stk.empty()) return false;
            else if(stk.top() != '[') return false;
            else stk.pop();
        }
    }
    return stk.empty();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        getline(cin, s);
        if(s == ".") break;
        if(check(s)) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}