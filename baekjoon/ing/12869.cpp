// 백준 12869 :: 뮤탈리스크(https://www.acmicpc.net/problem/12869)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, tmp, min_ret;
int scv[3];
vector<int> v;
vector<int> mutal = { 9, 3, 1 };

void go(int cnt, int a, int b, int c) {

	if (a <= 0 && b <= 0 && c <= 0) {
		min_ret = min(min_ret, cnt);
		return;
	}
	
	go(cnt + 1, a - 9, b - 3, c - 1);
	go(cnt + 1, a - 9, b - 1, c - 3);
	go(cnt + 1, a - 3, b - 9, c - 1);
	go(cnt + 1, a - 3, b - 1, c - 9);
	go(cnt + 1, a - 1, b - 9, c - 3);
	go(cnt + 1, a - 1, b - 3, c - 9);
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> scv[i];
		//v.push_back(tmp);
	}

	min_ret = 1e9;
	go(0, scv[0], scv[1], scv[2]);

	cout << min_ret << "\n";

	return 0;
}


/*
while (true) {

		ret++;

		sort(v.begin(), v.end(), greater<int>());
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			v[i] -= mutal[i];
			if (v[i] <= 0) cnt++;
		}

		if (cnt == v.size()) {
			cout << ret << "\n";
			break;
		}
	}

*/
