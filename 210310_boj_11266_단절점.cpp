#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> a[10001];
bool c[10001], cut[10001];
int low[10001], num[10001], parent[10001];
int cnt = 0;

void dfs(int x) {
	c[x] = true;
	num[x] = ++cnt;
	low[x] = cnt;
	int children = 0;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!c[y]) {
			children += 1;
			parent[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (parent[x] == 0 && children >= 2) { // 루트라면
				cut[x] = true;
			}
			if (parent[x] != 0 && low[y] >= num[x]) { // 루트가 아니면 (u, v)가 Tree edge
				cut[x] = true;
			}
		}
		else if (y != parent[x]) { // Back edge
			low[x] = min(low[x], num[y]);
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i++) {
		if (!c[i]) {
			dfs(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (cut[i]) {
			ans += 1;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (cut[i]) {
			printf("%d ", i);
		}
	}
	return 0;
}