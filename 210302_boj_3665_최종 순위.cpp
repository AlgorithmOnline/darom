#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int t, n, m;

int main() {
	scanf("%d", &t);
	while (t--) {
		int adj[501][501] = { 0 }, indegree[501] = { 0 }, arr[501] = { 0 };
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < j; i++) {
				adj[arr[i]][arr[j]] = 1;
				indegree[arr[j]]++;
			}
		}
		scanf("%d", &m);
		for (int i = 0, x, y; i < m; i++) {
			scanf("%d %d", &x, &y);
			if (adj[x][y]) {
				indegree[y]--;
				indegree[x]++;
			}
			else {
				indegree[y]++;
				indegree[x]--;
			}
			swap(adj[x][y], adj[y][x]);
		}

		// 위상정렬
		queue<int> q;
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) q.push(i);
		}
		int flg = 0;
		for (int i = 0; i < n; i++) {
			if (q.empty()) {
				flg = 1; break;
			}
			else if (q.size() > 1) {
				flg = 2; break;
			}
			int cur = q.front();
			q.pop();
			ans.push_back(cur);

			for (int j = 1; j <= n; j++) {
				if (!adj[cur][j]) continue;
				if (--indegree[j] == 0) {
					q.push(j);
				}				
			}
		}

		if (flg == 1) printf("IMPOSSIBLE\n");
		else if (flg == 2) printf("?\n");
		else {
			for (int i = 0; i < n; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}	

	return 0;
}