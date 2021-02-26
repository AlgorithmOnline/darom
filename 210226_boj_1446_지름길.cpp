#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
typedef pair<int, int> p;
int n, m;
vector<p> adj[10005];
priority_queue<p> pq;
int Dijkstra(int st, int ed) {
	vector<int> dist(10005, INF);
	pq.push({ 0, st });
	dist[st] = 0;
	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();
		int cur = front.second;
		int cost = -front.first;

		if (dist[cur] < cost) continue;
		for (auto e : adj[cur]) {
			int next = e.first;
			int ncost = e.second;
			if (dist[next] > cost + ncost) {
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
		if (cur + 1 <= ed && dist[cur + 1] > cost + 1) {
			dist[cur + 1] = cost + 1;
			pq.push({ -(cost + 1), cur + 1 });
		}
	}
	return dist[ed];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0, a, b, c; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b, c });
	}
	printf("%d", Dijkstra(0, m));
	return 0;
}