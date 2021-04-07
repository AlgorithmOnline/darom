#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int Max, Min = 1e9;
string str;

int OddCnt(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret += (s[i] - '0') % 2;
	}
	return ret;
}

void go(string s, int oddCnt) {
	string next = "";
	if (s.length() >= 3) {
		// 세 부분으로 나눈 뒤 홀수이면 oddCnt 를 증가
		for (int i = 1; i < s.length(); i++) {
			for (int j = i + 1; j < s.length(); j++) {
				int a = stoi(s.substr(0, i));
				int b = stoi(s.substr(i, j - i));
				int c = stoi(s.substr(j));
				next = to_string(a + b + c);

				go(next, oddCnt + OddCnt(next));
			}
		}
	}
	else if (s.length() == 2) {
		int n1 = stoi(s.substr(0, 1)), n2 = stoi(s.substr(1));
		next = to_string(n1 + n2);
		go(next, oddCnt + OddCnt(next));
	}
	else if (s.length() == 1) { // 마지막에 본 문자열의 홀수 개수 더하기
		Max = max(oddCnt + OddCnt(str), Max);
		Min = min(oddCnt + OddCnt(str), Min);
		return;
	}
}

int main() {
	cin >> str;
	go(str, 0);

	printf("%d %d", Min, Max);
	return 0;
}