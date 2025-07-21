// 백준 16637 : 괄호 추가하기(https://www.acmicpc.net/problem/16637)
#include <iostream>
using namespace std;
int n;
string s;

int calculator(int a, int b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else return a * b;
}

void go(int idx, int result) {

	if (idx == n) return;

	

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; 
	cin >> s; 

	// 왼쪽 괄호 결정 >> 오른쪽 괄호 자동 결정
	// 괄호 형성 가능하게 왼쪽 괄호 넣을 인덱스 선택 >> 조합?

	// 괄호 형성 가능 여부 상관 없이 완전 탐색 되는 지 판별
		// 수식 길이 >> 19 >> 숫자 10개 >> 기호 9개
		// 최대 괄호 5개
		// 19C1 + 19C2 + 19C3 + 19C4 + 19C5 = 약 2만 

	



	return 0;
}
