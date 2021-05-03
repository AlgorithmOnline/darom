#include <iostream>
#include <vector>
using namespace std;
int n, m, arr[505][505];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] && arr[k][j]) {
					arr[i][j] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool flg = false;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (!arr[i][j] && !arr[j][i]) {
				flg = true; break;
			}
		}
		if (flg) continue;
		ans++;
	}
	printf("%d", ans);
	return 0;
}