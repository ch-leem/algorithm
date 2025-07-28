// 백준 16637 : 괄호 추가하기(https://www.acmicpc.net/problem/16637)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define prev chan
typedef long long ll;
using namespace std;
int n, visited[20];
ll max_ret;
string s;
vector<int> v;

// 기본 연산 함수
ll apply(ll a, string b, ll c) {

	if (b == "+") return (a + c);
	else if (b == "-") return (a - c);
	else return (a * c);
}

//// 괄호 계산하기
//string calculate_1() {
//	string ret_s = "";
//
//	
//
//	return ret_s;
//}

string calculate_1(string expr, const vector<int>& opIndices) {
	vector<char> tokens(expr.begin(), expr.end());

	// 뒤에서부터 처리해야 인덱스 꼬이지 않음
	for (int i = opIndices.size() - 1; i >= 0; --i) {
		int opIdx = opIndices[i];

		// 연산할 좌우 숫자
		int a = tokens[opIdx - 1] - '0';
		char op = tokens[opIdx];
		int b = tokens[opIdx + 1] - '0';

		int result = apply(a, op, b);

		// [왼쪽 숫자, 연산자, 오른쪽 숫자]를 삭제하고 결과값 삽입
		tokens.erase(tokens.begin() + opIdx - 1, tokens.begin() + opIdx + 2);
		string resStr = to_string(result);
		tokens.insert(tokens.begin() + opIdx - 1, resStr.begin(), resStr.end());
	}

	return string(tokens.begin(), tokens.end());
}

// 수식 계산하기 (좌 -> 우)
ll calculate_2(string input) {

	ll result = stoll(string(1, input[0]));

	for (int i = 1; i < s.size(); i += 2) {
		string op = string(1, input[i]);
		ll num = stoll(string(1, input[i + 1]));
		result = apply(result, op, num);
	}

	return result;
}

// 조건에 맞게 괄호한 수식인 지 확인
bool check() {
	bool flag = true;

	int a = v[0];
	for (int i = 1; i < v.size(); i++) {
		if ((v[i] - a) == 1) flag = false;
	}

	return flag;
}

// 기호 순회하며 괄호 여부 완전 탐색 (모든 경우의 수)
void go(int idx, int b) {

	if (b == 1) {
		v.push_back(idx);
	}

	if (idx == n - 1) {
		if (v.size()) {
			if (check()) {
				string tmp = calculate_1(s, v);
				max_ret = max(max_ret, calculate_2(tmp));
				return;
			}
			else {
				v.pop_back();
				return;
			}

		}
		else {
			max_ret = max(max_ret, calculate_2(s));
			return;
		}
	}

	if ((idx+1) % 2 == 0) go(idx + 1, 0);
	else {
		go(idx + 1, 1);
		go(idx + 1, 0);
	}
	
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;

	for (int i = 0; i < 20; i++) {
		if (i % 2) continue;
		visited[i] = 3;
	}
	max_ret = -1e19;

	go(0, 0); // 숫자로 시작

	cout << max_ret << "\n";

	return 0;
}
