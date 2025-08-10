// 백준 12869 :: 뮤탈리스크(https://www.acmicpc.net/problem/12869)
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int scv[3], visited[61][61][61];
vector<int> mutal = { 9,3,1 };
vector<vector<int>> v; 

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> scv[i];
	}

	struct A {
		int a, b, c;
	};

	queue<A> q;
	q.push({ scv[0], scv[1], scv[2] });
	visited[scv[0]][scv[1]][scv[2]] = 1;

	sort(mutal.begin(), mutal.end());
	do {
		vector<int> tmp;
		for (auto i : mutal) tmp.push_back(i);
		v.push_back(tmp);

	} while (next_permutation(mutal.begin(), mutal.end()));

	while (!q.empty()) {

		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;

		q.pop();
		if (visited[0][0][0]) break;

		for (vector<int> tmp : v) {
			int na = max(0, a - tmp[0]);
			int nb = max(0, b - tmp[1]);
			int nc = max(0, c - tmp[2]);
			
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;

			q.push({ na, nb, nc });
		}
	}

	cout << visited[0][0][0]-1 << "\n";

	return 0;
}
