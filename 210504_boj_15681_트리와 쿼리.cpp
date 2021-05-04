#include <iostream>
#include <vector>
using namespace std;
int n, r, q, dp[100005];
vector<vector<int>> adj;

void go(int now, int parent) {
	for (auto next : adj[now]) {
		if (parent == next) continue;
		go(next, now);
	}
	dp[now] = 1;
	for (auto next : adj[now]) {
		if (parent == next) continue;
		dp[now] += dp[next];
	}
}

int main() {
	scanf("%d %d %d", &n, &r, &q);
	adj.resize(n + 1);
	for (int i = 0, u, v; i < n - 1; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	go(r, 0);

	while (q--) {
		int a;
		scanf("%d", &a);
		printf("%d\n", dp[a]);
	}	

	return 0;
}