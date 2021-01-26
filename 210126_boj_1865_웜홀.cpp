#include <cstdio>
#include <vector>
using namespace std;
struct Edge {
	int from;
	int to;
	int cost;
};
int dist[501];
int inf = 1e9;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		vector<Edge> a(2 * m + w); // 0 ~ m-1 순방향, m ~ 2 * m - 1 역방향
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
			a[i + m] = a[i];
			swap(a[i + m].from, a[i + m].to);
		}
		for (int i = 2 * m; i < 2 * m + w; i++) {
			scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
			a[i].cost *= -1; // 웜홀내 시간은 거꾸로 감
		}
		for (int i = 1; i <= n; i++) {
			dist[i] = inf;
		}
		dist[1] = 0;
		m = 2 * m + w;
		bool negative_cycle = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				int x = a[j].from;
				int y = a[j].to;
				int z = a[j].cost;
				if (dist[y] > dist[x] + z) {
					dist[y] = dist[x] + z;
					if (i == n) negative_cycle = true;
				}
			}
		}
		if (negative_cycle) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}