// 백준 16202 : MST 게임 (https://www.acmicpc.net/problem/16202)
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int n, m, k, ret;
int from, to;
int tree[1004][1004], parent[1004];
vector<pair<int, int>> node;
bool found, zero;

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
} // 루트 노드 반환

bool union_set(int a, int b) {
    a = find(a); // a의 루트 노드
    b = find(b); // b의 루트 노드
    if (a == b) return false; // 연결하면 싸이클 생김 -> False
    parent[b] = a; // 연결하고 True 리턴
    return true;
}

int main() {

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        tree[from][to] = i + 1;
        tree[to][from] = i + 1;
        node.push_back({ from, to });
    }

    int u1, v1;
    zero = false;
    for (int i = 0; i < k; i++) {

        if (zero) {
            cout << 0 << " ";
            continue;
        }

        for (int j = 1; j <= m; j++) parent[j] = j;

        int edge = 0;
        int cost = 0;
        for (int j = 0; j < m; j++) {
            int u, v;
            tie(u, v) = node[j];
            if (tree[u][v] == 0) continue;

            if (union_set(u, v)) {
                cost += tree[u][v];
                edge++;
                if (edge == n - 1) break;
            }
        }

        if (edge == n - 1) ret = cost;
        else {
            ret = 0;
            zero = true;
        }

        cout << ret << " ";

        // 가장 작은 간선 제거 
        tie(u1, v1) = node[i];
        tree[u1][v1] = 0;
        tree[v1][u1] = 0;
    }

    return 0;
}
