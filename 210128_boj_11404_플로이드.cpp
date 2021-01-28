#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, d[101][101];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0, x, y, z; i < m; i++){
		scanf("%d%d%d", &x, &y, &z);
		if (d[x][y] == 0) {
			d[x][y] = z;
		}
		else {
			d[x][y] = min(d[x][y], z);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] == 0) {
						d[i][j] = d[i][k] + d[k][j];
					}
					else {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}