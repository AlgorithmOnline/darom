#include <cstdio>
#include <queue>
using namespace std;
int d[101][101];
int a[101][101];
int n, m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}
	}
	priority_queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {0, 0} });
	d[0][0] = 0;
	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (d[nx][ny] == -1) {
				if (a[nx][ny] == 0) {
					d[nx][ny] = d[x][y];
				}
				else {
					d[nx][ny] = d[x][y] + 1;
				}
				q.push({ -d[nx][ny], {nx, ny} });
			}
		}
	}
	printf("%d", d[n - 1][m - 1]);
	return 0;
}