#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 500001;
int n, k, ans = MAX;
bool visit[MAX][2];

int solve(int os, int ys) {
	int time = 0;
	queue<pair<int, int>> q;
	q.push({ os, 0 });
	visit[os][time] = true;
	while (1) {
		ys += time;
		if (ys >= MAX) return -1;
		if (visit[ys][time % 2]) return time;

		for (int i = 0, size = q.size(); i < size; i++) {
			int curPosition = q.front().first; // os 위치
			int nextTime = (q.front().second + 1) % 2;
			int nextPosition = 0;
			q.pop();

			nextPosition = curPosition - 1;
			if (nextPosition >= 0 && !visit[nextPosition][nextTime]) {
				visit[nextPosition][nextTime] = true;
				q.push({ nextPosition , nextTime });
			}
			nextPosition = curPosition + 1;
			if (nextPosition < MAX && !visit[nextPosition][nextTime]) {
				visit[nextPosition][nextTime] = true;
				q.push({ nextPosition , nextTime });
			}
			nextPosition = curPosition * 2;
			if (nextPosition < MAX && !visit[nextPosition][nextTime]) {
				visit[nextPosition][nextTime] = true;
				q.push({ nextPosition , nextTime });
			}
		}
		time++;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	
	printf("%d", solve(n, k));	
	return 0;
}