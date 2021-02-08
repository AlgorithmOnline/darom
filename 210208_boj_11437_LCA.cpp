#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100111;
vector<int> a[MAX];
int parent[MAX], depth[MAX];
bool check[MAX];

int lca(int u, int v) {
	if (depth[u] < depth[v]) { // u > v 라고 가정
		swap(u, v);
	}
	while (depth[u] != depth[v]) {
		u = parent[u];
	}
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
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
	int m;
	scanf("%d", &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}