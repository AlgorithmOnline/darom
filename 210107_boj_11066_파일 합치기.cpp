#include <cstdio>
#include <cstring>
int t, arr[501], sum[501];
int dp[501][501];
int go(int i, int j) {
	if (i == j) return 0;
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int& ret = dp[i][j];
	for (int k = i; k <= j - 1; k++) {
		int tmp = go(i, k) + go(k + 1, j) + sum[j] - sum[i - 1];
		if (ret == -1 || ret > tmp) {
			ret = tmp;
		}
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
		}
		printf("%d\n", go(1, n));
	}
	return 0;
}