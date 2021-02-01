#include <cstdio>
int d[401][401];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (d[x][y] == 0) {
			d[x][y] = z;
		}
		else if (d[x][y] > z) {
			d[x][y] = z;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j]) {
					if (d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
	}
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (d[i][i] != 0) {
			if (ans == -1 || ans > d[i][i]) {
				ans = d[i][i];
			}
		}
	}
	printf("%d", ans);
	return 0;
}