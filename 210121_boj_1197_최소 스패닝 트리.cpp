#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int parent[10001];
struct Edge {
	int start, end, cost;
	bool operator < (const Edge& other) const {
		return cost < other.cost;
	}
};
int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	vector<Edge> a(m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i].start, &a[i].end, &a[i].cost);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < m; i++) {
		auto e = a[i];
		int x = Find(e.start);
		int y = Find(e.end);
		if (x != y) {
			Union(e.start, e.end);
			ans += e.cost;
		}
	}
	printf("%d", ans);
	return 0;
}