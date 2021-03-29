#include <cstdio>
#include <vector>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, ans, chk[31][31];
double percent[4];

double dfs(int x, int y, int cnt) {
	if (cnt == n) return 1.0;

	chk[x][y] = 1;
	double ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (chk[nx][ny]) continue;
		ret += percent[i] * dfs(nx, ny, cnt + 1);
	}
	chk[x][y] = 0;
	return ret;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		scanf("%lf", &percent[i]);
		percent[i] *= 0.01;
	}
	
	printf("%.10lf", dfs(14, 14, 0));

	return 0;
}