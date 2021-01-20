#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, time[505], indegree[505], dp[505];
vector<vector<int>> adj;
int main() {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1, a; i <= n; i++) {
		scanf("%d%d", &time[i], &a);
		while (a >= 1) {
			adj[a].push_back(i);
			indegree[i]++;
			scanf("%d", &a);
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) {
			q.push(i);
		}
	}	
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (auto next : adj[here]) {
			dp[next] = max(dp[next], dp[here] + time[here]);
			if (--indegree[next] == 0) {				
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", dp[i] + time[i]);
	}
	return 0;
}