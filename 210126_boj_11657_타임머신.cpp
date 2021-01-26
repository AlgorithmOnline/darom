#include <cstdio>
#include <vector>
using namespace std;
struct Edge {
	int from;
	int to;
	int cost;
};
long long int dist[501];
int inf = 1e9;
int main() {
	int t, n, m;
	scanf("%d %d", &n, &m);
	vector<Edge> a(m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	dist[1] = 0;
	bool negative_cycle = false;
	for (int i = 1; i <= n; i++) { // 원래는 n - 1번까지만 돌면 최단거리 완성
		for (int j = 0; j < m; j++) {
			int x = a[j].from;
			int y = a[j].to;
			int z = a[j].cost;
			if (dist[x] != inf && dist[y] > dist[x] + z) {
				dist[y] = dist[x] + z;
				if (i == n) { // n번째에서 갱신이 된다면 음수사이클
					negative_cycle = true;
				}
			}
		}
	}
	if (negative_cycle) {
		printf("-1");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == inf) dist[i] = -1;
			printf("%lld\n", dist[i]);
		}
	}
	return 0;
}