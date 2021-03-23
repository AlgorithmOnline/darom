#include <iostream>
#include <queue>
#define ABS(x) ((x) > 0 ? (x) : -(x))
using namespace std;
int visited[50][50], map[50][50];
int N, L, R;
bool chk = true;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ans, ch;
int main() {
	ios_base::sync_with_stdio(false);	
	queue<pair<int, int>> q;
	queue<pair<int, int>> pos; 
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	while (chk) {
		++ch;
		chk = false; ans += 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == ch) continue;
				int sum = map[i][j];
				q.push({ j, i });
				pos.push({ j, i });
				visited[i][j] = ch;

				while (!q.empty()) {
					int x_tmp = q.front().first;
					int y_tmp = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int x = x_tmp + dx[k];
						int y = y_tmp + dy[k];
						if (x < 0 || y < 0 || x >= N || y >= N || visited[y][x] == ch || ABS(map[y_tmp][x_tmp] - map[y][x]) < L || ABS(map[y_tmp][x_tmp] - map[y][x]) > R)
							continue;
						chk = true;
						q.push({ x, y });
						pos.push({ x, y });
						sum += map[y][x];
						visited[y][x] = ch;
					}
				}

				int avr = sum / pos.size();
				while (!pos.empty()) {
					map[pos.front().second][pos.front().first] = avr;
					pos.pop();
				}
			}
		}
	}
	cout << ans - 1;
}