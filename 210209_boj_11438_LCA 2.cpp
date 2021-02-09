#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100001;
vector<int> a[MAX];
int parent[MAX], depth[MAX], p[MAX][18];
bool check[MAX];

int lca(int u, int v) {
	if (depth[u] < depth[v]) { // u > v 라고 가정
		swap(u, v);
	}
	int log = 1; // 높이
	for (log = 1; (1 << log) <= depth[u]; log++);
	log--;

	for (int i = log; i >= 0; i--) { // u, v level 맞추기
		if (depth[u] - (1 << i) >= depth[v]) u = p[u][i];
	}
	if (u == v) return u;
	
	for (int i = log; i >= 0; i--) {
		if (p[u][i] != 0 && p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return parent[u];	
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	depth[1] = 0;
	check[1] = true;
	queue<int> q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty()) {	// BFS 탐색으로 depth, parent구하기
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		p[i][0] = parent[i];
	}
	for (int j = 1; (1 << j) < n; j++) { // 2^1 ~ 2^j 번째 조상 찾기
		for (int i = 1; i <= n; i++) {
			if (p[i][j - 1] != 0) { // 조상이 있으면
				p[i][j] = p[p[i][j - 1]][j - 1];
			}
		}
	}
	
	int m;
	scanf("%d", &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}