#include <cstdio>
#include <vector>
using namespace std;
#define MAX 1025
int n, m, sum[MAX][MAX];
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1, a; j <= n; j++) {
			scanf("%d", &a);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a;
		}
	}
	for (int i = 0, a, b, c, d; i < m; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1]);
	}
	return 0;
}