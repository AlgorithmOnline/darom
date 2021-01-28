#include <cstdio>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
vector<pair<int, int>> a[20001];
int dist[20001];
bool check[20001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int start;
	scanf("%d", &start);
	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	priority_queue<pair<int, int>> q;
	q.push({ 0, start });
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		int x = p.second;
		if (check[x]) {
			continue;
		}
		check[x] = true;
		for (auto e : a[x]) {
			int next = e.first;
			int cost = e.second;
			if (dist[next] > dist[x] + cost) {
				dist[next] = dist[x] + cost;
				q.push({ -dist[next], next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] >= INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", dist[i]);
		}
	}
	return 0;
}