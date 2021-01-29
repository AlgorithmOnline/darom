#include <cstdio>
int d[101][101];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = n + 1;
		}
	}

	for (int i = 0, x, y; i < m; i++) {
		scanf("%d %d", &x, &y);
		d[x][y] = d[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	int ans = -1;
	int who = -1;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			sum += d[i][j];
		}
		if (ans == -1 || ans > sum) {
			ans = sum;
			who = i;
		}
	}
	printf("%d", who);
	return 0;
}