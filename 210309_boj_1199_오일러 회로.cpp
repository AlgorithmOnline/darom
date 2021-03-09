#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int n;
int a[1001][1001];
stack<pair<int, int>> s;
stack<int> ans;

// 그래프의 차수가 짝수인지 확인
bool check() {
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			cnt += a[i][j];
		}
		if (cnt % 2 != 0) {
			return false;
		}
		if (s.empty() && cnt > 0) { // 임의 시작점
			s.push({ i, 1 });
		}
	}
	return true;
}
bool go() {
	if (!check())	return false;
	// DFS를 비재귀로 구현
	while (!s.empty()) {
		int x = s.top().first;
		int y = s.top().second;
		s.pop();
		int i;
		for (i = y; i <= n; i++) {
			if (a[x][i] > 0) {
				a[x][i]--;
				a[i][x]--;
				s.push({ x, i });
				s.push({ i, 1 });
				break;
			}
		}
		if (i > n) {
			ans.push(x);
		}
	}
	return true;
}
void print_answer() {
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	printf("\n");
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	if (!go())	printf("-1\n");
	else print_answer();
	return 0;
}