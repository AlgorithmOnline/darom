#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 10000000;
int n, a[50], d[50][250001];

int go(int k, int diff) { // index, 높이 차이
	if (diff > 250000) {
		return -inf;
	}
	if (k == n) {
		if (diff == 0) {
			return 0;
		}
		else {
			return -inf;
		}
	}
	int& ans = d[k][diff];
	if (ans != -1) {
		return ans;
	}
	ans = go(k + 1, diff); // 놓지 않음
	ans = max(ans, go(k + 1, diff + a[k])); // 높은 탑에 추가
	// 낮은 탑에 추가
	if (a[k] > diff) {
		ans = max(ans, diff + go(k + 1, a[k] - diff));
	}
	else {
		ans = max(ans, a[k] + go(k + 1, diff - a[k]));
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	memset(d, -1, sizeof(d));
	int ans = go(0, 0);	
	printf("%d", ans > 0 ? ans : -1);

	return 0;
}