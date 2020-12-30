#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
vector<vector<p>> v;
bool chk[10001];
int n, m, st, ed;
bool go(int node, int limit) {
	if (chk[node]) return false;
	chk[node] = true;
	if (node == ed) return true;

	for (auto& p : v[node]) {
		int next = p.first;
		int cost = p.second;
		if (cost >= limit) {
			if (go(next, limit))
				return true;
		}
	}
	return false;
}
int main() {
	
	scanf("%d%d", &n, &m);
	v.resize(n + 1);
	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	scanf("%d%d", &st, &ed);

	int left = 1, right = 1e9, ans = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2; // 모든 단계가 right보다 작아지면서 오버플로우가 나지 않음
		memset(chk, false, sizeof(chk));
		if (go(st, mid)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%d", ans);
	return 0;
}