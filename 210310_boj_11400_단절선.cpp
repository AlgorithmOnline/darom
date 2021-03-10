#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> a[100001];
bool c[100001], cut[100001];
int low[100001], num[100001], parent[100001], cnt = 0;
vector<pair<int, int>> ans;
void dfs(int x) {
	c[x] = true;
	num[x] = ++cnt;
	low[x] = cnt;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!c[y]) {
			parent[y] = x;
			dfs(y);
			low[x] = min(low[x], low[y]);
			if (low[y] > num[x]) { // 서로 다른 컴포넌트
				if (x < y) ans.emplace_back(x, y); // A < B를 만족해야 한다.
				else ans.emplace_back(y, x);
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
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (auto& p : ans) {
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}