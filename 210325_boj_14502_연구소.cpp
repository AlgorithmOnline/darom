#include<iostream>
#include<vector>
#include<queue>
#define MAX 10
using namespace std;
int arr[MAX][MAX];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0 ,-1 ,0 };
int n, m, ans;
queue<pair<int, int>> Q;

void go(int x, int y, int cnt) {
	if (cnt == 3) {
		int chk[MAX][MAX] = { 0 };
		queue<pair<int, int>> q = Q;
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i], nc = c + dy[i];
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] || chk[nr][nc]) continue;
				chk[nr][nc] = 2;
				q.push({ nr, nc });
			}
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!chk[i][j] && !arr[i][j]) ret++;
			}
		}
		ans = max(ans, ret);
		return;
	}
    if (x >= n) return;
    
	int nx, ny;
	ny = (y + 1) % m;
	if (ny == 0) nx = x + 1;
	else nx = x;
	if (arr[x][y] == 0) {
		arr[x][y] = 1;
		go(nx, ny, cnt + 1);
		arr[x][y] = 0;
	}
	go(nx, ny, cnt);
}

int main(void) {
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) Q.push({ i, j });
		}
	}
	go(0, 0, 0);
	printf("%d", ans);

	return 0;
}