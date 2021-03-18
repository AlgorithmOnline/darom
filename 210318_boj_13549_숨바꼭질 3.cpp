#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, k;
int dist[100001];
int main() {
	scanf("%d%d", &n, &k);
	queue<int> q;
	q.push(n);
	dist[n] = 1; // 마지막 ans에 1빼줘야 함
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) {
			continue;
		}

		if (cur - 1 >= 0) {
			if (!dist[cur - 1] || dist[cur - 1] >= dist[cur] + 1) {
				dist[cur - 1] = dist[cur] + 1;
				q.push(cur - 1);
			}
		}
		if (cur + 1 <= 100000) {
			if (!dist[cur + 1] || dist[cur + 1] >= dist[cur] + 1) {
				dist[cur + 1] = dist[cur] + 1;
				q.push(cur + 1);
			}
		}
		if (cur * 2 <= 100000) {
			if (!dist[cur * 2] || dist[cur * 2] >= dist[cur] + 1) {
				dist[cur * 2] = dist[cur];
				q.push(cur * 2);
			}
		}
	}
	printf("%d", dist[k] - 1);
	return 0;
}