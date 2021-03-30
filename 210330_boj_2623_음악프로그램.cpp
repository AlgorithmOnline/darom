#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int N, M, indegree[1005];

int main(void) {
	scanf("%d%d", &N, &M);
	vector<vector<int>> adj(N + 1);
	for (int i = 0, a; i < M; i++) {
		scanf("%d", &a);
		int b;
		scanf("%d", &b);
		for (int j = 1, c; j < a; j++) {
			scanf("%d", &c);
			adj[b].push_back(c);
			indegree[c]++;
			b = c;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) { q.push(i); }
	}
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			printf("0"); return 0;
		}
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for (auto e : adj[x]) {
			if (--indegree[e] == 0) {
				q.push(e);
			}
		}
	}
	for (auto e : ans) {
		printf("%d\n", e);
	}
	
	return 0;
}