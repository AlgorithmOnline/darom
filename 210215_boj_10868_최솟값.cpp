#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
#define INF 1e9
int n, m, h = 1;
vector<ll> seg;
void update(int i, int num) {
	i += h;
	seg[i] = num;
	while (i > 1) {
		i /= 2;
		seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	}
}
// l, r 찾는 범위, num 현재 노드 번호, nl, nr 현재 범위
ll query(int l, int r, int num, int nl, int nr) {
	if (l <= nl && nr <= r) return seg[num];
	if (nl > r || nr < l) return INF;

	int mid = (nl + nr) / 2;
	return min(query(l, r, num * 2, nl, mid), query(l, r, num * 2 + 1, mid + 1, nr));
}

int main() {
	scanf("%d%d", &n, &m);
	while (h < n) h <<= 1;
	seg.resize(h * 2);
	fill(seg.begin(), seg.end(), INF);
	for (int i = 0, a; i < n; i++) {
		scanf("%d", &a);
		update(i, a);
	}
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		printf("%lld\n", query(a, b, 1, 1, h));
	}
	return 0;
}