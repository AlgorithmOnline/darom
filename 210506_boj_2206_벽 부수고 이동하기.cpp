#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int n, m, arr[1005][1005], chk[1005][1005][2]; // x, y, 벽 부쉈으면 1 아니면 0
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

int go() {
	chk[0][0][0] = 1;
	queue<pair<pair<int, int>, int>> q; // (x, y), 벽 부쉈으면 true, 아니면 false
	q.push({ {0, 0}, 0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			return chk[x][y][block];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || chk[nx][ny][block]) continue;
			if (!arr[nx][ny]) {
				chk[nx][ny][block] = chk[x][y][block] + 1;
				q.push({ {nx, ny}, block });
			}
			else if (!block && arr[nx][ny]) {
				chk[nx][ny][1] = chk[x][y][block] + 1;
				q.push({ {nx, ny}, 1 });
			}
		}

	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	printf("%d", go());

	return 0;
}