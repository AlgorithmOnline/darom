#include<iostream>
#include<string.h>
#include<queue>
#define inf 1e9
using namespace std;
typedef pair<int, int> p;
int n, arr[25][25], chk[25][25], shark_size = 2, Min, cnt, ans;
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
p shark, Min_p;
void bfs(int x, int y) {
	queue<p> q;
	q.push({ x, y });
	chk[x][y] = 0;
	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i], nc = c + dy[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
			if (arr[nr][nc] > shark_size || chk[nr][nc] >= 0) continue;

			chk[nr][nc] = chk[r][c] + 1;
			if (arr[nr][nc] && arr[nr][nc] < shark_size) {
				if (Min > chk[nr][nc]) {
					Min = chk[nr][nc];
					Min_p.first = nr; Min_p.second = nc;
				}
				else if (Min == chk[nr][nc]) {
					if (Min_p.first > nr || (Min_p.first == nr && Min_p.second > nc)) {
						Min_p.first = nr; Min_p.second = nc;
					}
				}
			}
			q.push({ nr, nc });
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				shark = { i,j }; arr[i][j] = 0;
			}
		}
	}
	while (1) {
		Min = Min_p.first = Min_p.second = inf;
		memset(chk, -1, sizeof(chk));

		bfs(shark.first, shark.second);

		if (Min == inf) break;
		ans += Min;
		shark = { Min_p.first, Min_p.second };
		arr[Min_p.first][Min_p.second] = 0;

		cnt++;
		if (cnt == shark_size) {
			shark_size++;
			cnt = 0;
		}
	}
	printf("%d", ans);

	return 0;
}