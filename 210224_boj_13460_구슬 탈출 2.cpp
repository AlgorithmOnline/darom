#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 15
typedef pair<int, int> p;
int n, m, ans = MAX, rx, ry, bx, by;
char arr[MAX][MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int dist[MAX][MAX][MAX][MAX];

pair<p, p> move(pair<p, p> node, int dx, int dy) {
	int rx = node.first.first, ry = node.first.second;
	int bx = node.second.first, by = node.second.second;

	while (1) { // RED
		if(arr[rx][ry] == 'O') break;

		if (arr[rx + dx][ry + dy] != 'O') {
			if (arr[rx + dx][ry + dy] != '.') break; // #
			if (rx + dx == bx && ry + dy == by) { // BULE
				while (1) {
					if (arr[bx][by] == 'O')break;

					if (arr[bx + dx][by + dy] != 'O') {
						if (arr[bx + dx][by + dy] != '.') break;
						if (bx + dx == rx && by + dy == ry) break;
					}
					bx += dx, by += dy;
				}
				if (rx + dx == bx && ry + dy == by) break;
			}
		}
		rx += dx, ry += dy;
	}

	while (1) { // BULE
		if (arr[bx][by] == 'O')break;

		if (arr[bx + dx][by + dy] != 'O') {
			if (arr[bx + dx][by + dy] != '.') break; // #
			if (bx + dx == rx && by + dy == ry) break;
		}
		bx += dx, by += dy;
	}

	return { {rx, ry}, {bx, by} };
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'R') {
				rx = i, ry = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				bx = i, by = j;
				arr[i][j] = '.';
			}
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<pair<p, p>> q;
	q.push({ {rx, ry},{bx, by} });
	dist[rx][ry][bx][by] = 0;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int cnt = dist[cur.first.first][cur.first.second][cur.second.first][cur.second.second];
		if (cnt >= 10) continue;

		for (int k = 0; k < 4; k++) {
			auto next = move(cur, dx[k], dy[k]);
			rx = next.first.first, ry = next.first.second;
			bx = next.second.first, by = next.second.second;

			if (arr[bx][by] == 'O') continue;

			if (arr[rx][ry] == 'O') {
				printf("%d", cnt + 1);
				return 0;
			}
			else {
				if (dist[rx][ry][bx][by] == -1) {
					dist[rx][ry][bx][by] = cnt + 1;
					q.push({ {rx, ry}, {bx, by} });
				}
			}
		}
	}
	
	printf("-1");
	return 0;
}