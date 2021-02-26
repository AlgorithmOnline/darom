#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
typedef pair<int, int> p;
int n, m, arr[55][55], ans = INF;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<p> virus;
bool chk[11];
// 0 : 빈칸, 1 : 벽, 2 : 바이러스를 놓을 수 있는 칸
int dist[55][55];

void go(int idx, int cnt) {
	if (cnt == m) {
		// BFS
		queue<p> q;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) dist[i][j] = -1;

		for (int i = 0; i < virus.size(); i++) {
			if (chk[i]) {
				q.push({ virus[i].first, virus[i].second });
				dist[virus[i].first][virus[i].second] = 0;
			}
		}
		int time = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			time = time < dist[x][y] ? dist[x][y] : time;
			if (time > ans) return; // 이미 정답이 아님

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == 1 || dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[x][y] + 1;
				q.push({ nx, ny });
			}
		}
		bool flg = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] == -1 && arr[i][j] != 1) { // 바이러스가 전부 퍼지지 못함
					flg = false;
				}
			}
		}
		if(flg)	ans = ans > time ? time : ans;
		return;
	}
	if (idx >= virus.size()) return;

	if (!chk[idx] && cnt < m) {
		chk[idx] = true;
		go(idx + 1, cnt + 1);
		chk[idx] = false;
	}
	go(idx + 1, cnt);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) virus.push_back({ i, j });
		}
	}
	go(0, 0);
	printf("%d", ans == INF ? -1 : ans);
	return 0;
}