#include <cstdio>
#include <vector>
using namespace std;
vector<pair<int, int>> a[1001];
int dist[1001], visit[1001];
bool check[1001];
int n, m, inf = 1e9;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
	}
	int start, end;
	scanf("%d %d", &start, &end);
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	dist[start] = 0;
	visit[start] = -1;
	for (int k = 0; k < n - 1; k++) {
		int m = inf + 1;
		int x = -1;
		for (int i = 1; i <= n; i++) {
			if (check[i] == false && m > dist[i]) {
				m = dist[i];
				x = i;
			}
		}
		check[x] = true;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].first;
			if (dist[y] > dist[x] + a[x][i].second) {
				dist[y] = dist[x] + a[x][i].second;
				visit[y] = x; // y 이전에 x를 거침
			}
		}
	}
	printf("%d\n", dist[end]);
	vector<int> ans;
	int x = end;
	while (x != -1) {
		ans.push_back(x);
		x = visit[x];
	}
	printf("%d\n", ans.size());
	while (!ans.empty()) {
		printf("%d ", ans.back());
		ans.pop_back();
	}
	return 0;
}