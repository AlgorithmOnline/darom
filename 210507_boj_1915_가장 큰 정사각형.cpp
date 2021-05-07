#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, arr[1005][1005], dp[1005][1005];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!arr[i][j]) continue;
			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			Max = max(Max, dp[i][j]);
		}
	}
	
	printf("%d", Max * Max);

	return 0;
}