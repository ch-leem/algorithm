// 백준 : 17298 오큰수 (https://www.acmicpc.net/problem/17298)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n, tmp;
const int N = 1000004;
vector<int> a(N), ret(N, -1);
stack<int> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        while(!stk.empty() && a[stk.top()] < a[i]){
            ret[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i=0; i<n; i++){
        cout << ret[i] << " ";
    }
    cout << "\n";

    return 0;
}