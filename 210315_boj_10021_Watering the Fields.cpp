#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct info {
	int from, to;
	long long val;
};
struct cmp {
	bool operator()(info& a, info& b) {
		return a.val > b.val;
	}
};
info tmp;
int x[2001], y[2001], par[2001];

int find_par(int p) {
	if (par[p] == p) return p;
	return par[p] = find_par(par[p]);
}

void make_union(int a, int b) {
	a = find_par(a);
	b = find_par(b);
	if (a > b) par[a] = b;
	else if (a < b) par[b] = a;
}

int main() {
	int n, maxi, conn = 0;
	long long result = 0;
	scanf("%d%d", &n, &maxi);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		par[i] = i;
	}
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long dx = x[i] - x[j];
			long long dy = y[i] - y[j];
			long long v = dx * dx + dy * dy;
			tmp.from = i;
			tmp.to = j;
			tmp.val = v;
			pq.push(tmp);
		}
	}
	while (!pq.empty()) {
		int cf = pq.top().from;
		int ct = pq.top().to;
		long long cv = pq.top().val;
		pq.pop();
		if (cv < maxi) continue;
		int pf = find_par(cf);
		int pt = find_par(ct);
		if (pf == pt) continue;
		make_union(cf, ct);
		result += cv;
		conn++;
		if (conn == n - 1) break;
	}
	if (conn != n - 1) result = -1;
	printf("%lld", result);
	return 0;
}