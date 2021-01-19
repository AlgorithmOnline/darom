#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, indegree[32001];
vector<vector<int>> adj;
// 위상정렬을 이용하되, 민힙을 사용.
int main() {
	scanf("%d %d", &n, &m);
	adj.resize(n + 1);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq; // min-heap
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int front = pq.top();
		pq.pop();
		printf("%d ", front);
		for (auto e : adj[front]) {
			if (--indegree[e] == 0) {
				pq.push(e);
			}
		}
	}

	return 0;
}