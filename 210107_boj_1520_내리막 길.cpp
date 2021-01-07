#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int arr[505][505];
int dp[505][505];
int go(int x, int y) {
	if (x == n && y == m) return 1;
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
		if (arr[nx][ny] < arr[x][y]) {
			ret += go(nx, ny);
		}
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", go(1, 1));
	return 0;
}