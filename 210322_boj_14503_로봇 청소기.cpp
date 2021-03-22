#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[55][55], ans, chk[55][55];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void go(int x, int y, int dir) {
	if (!chk[x][y]) {
		chk[x][y] = ++ans;
	}

	int cnt = 0, nd = dir, nx = 0, ny = 0;
	for (int k = 0; k < 4; k++) {
		nd = (nd + 3) % 4; // 반시계방향(왼쪽방향)
		nx = x + dx[nd], ny = y + dy[nd];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || chk[nx][ny] || arr[nx][ny]) cnt++;
		else if (!chk[nx][ny] && !arr[nx][ny]) {
			go(nx, ny, nd);
		}
	}
	if (cnt >= 4) {
		// 바라보는 방향 유지한 채로 한 칸 후진
		nx = x - dx[dir], ny = y - dy[dir];
		if (arr[nx][ny]) {
			printf("%d", ans); exit(0);
		}
		else go(nx, ny, dir);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int x, y, d;
	scanf("%d%d%d", &x, &y, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}

	go(x, y, d);

	return 0;
}