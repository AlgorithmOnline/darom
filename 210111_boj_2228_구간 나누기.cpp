#include <stdio.h>
using namespace std;
int arr[101], sum[101], dp[101][101];
bool chk[101][101];
int min = -987654321;

int go(int n, int m) {
	if (m == 0) return 0;
	if (n <= 0) return min;
	if (chk[n][m]) return dp[n][m];

	chk[n][m] = true;
	int& ret = dp[n][m];
	ret = go(n - 1, m);
	for (int i = 1; i <= n; i++) {
		int tmp = go(i - 2, m - 1) + sum[n] - sum[i - 1];
		if (ret < tmp) ret = tmp;
	}
	return ret;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	printf("%d", go(n, m));
	return 0;
}