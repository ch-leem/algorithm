// 백준 12851 : 숨바꼭질 2 (https://www.acmicpc.net/problem/12851)
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
int n, k;
int visited[MAX + 4];
int cnt[MAX + 4];

int main(){

    cin >> n >> k;

    if(n == k){
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;

    while(!q.empty()){
        int pos = q.front(); q.pop();

        // 종료 조건
        if(pos == k){
            cout << visited[pos] - 1 << "\n" << cnt[pos] << "\n";
            return 0;
        }

        for(int next : {pos - 1, pos + 1, pos * 2}){

            if(next < 0 || next > MAX) continue;
           
            if(visited[next] == 0){
                visited[next] = visited[pos] + 1;
                cnt[next] = cnt[pos];
                q.push(next);
            }
            else if(visited[next] == visited[pos] + 1){
                cnt[next] += cnt[pos];
            }
        }
    }

    return 0;
}