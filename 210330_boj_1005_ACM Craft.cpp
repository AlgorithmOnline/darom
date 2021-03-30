#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int T, N, K, W;
int arr[1005], indegree[1005], cost[1005];

int main(void) {
	scanf("%d", &T);
	while (T--) {
		memset(indegree, 0, sizeof(indegree));
		memset(cost, 0, sizeof(cost));

		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}
		vector<vector<int>> adj(N + 1);
		for (int i = 0, a, b; i < K; i++) {
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			indegree[b]++;
		}
		scanf("%d", &W);
		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (!indegree[i]) { cost[i] = arr[i]; q.push(i); }
		}
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto e : adj[x]) {
				cost[e] = max(cost[e], cost[x] + arr[e]);
				if (--indegree[e] == 0) {
					q.push(e);
				}
			}
		}
		printf("%d\n", cost[W]);
	}
	return 0;
}