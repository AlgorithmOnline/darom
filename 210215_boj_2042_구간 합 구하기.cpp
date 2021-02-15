#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;
int n, m, k, h = 1;
vector<ll> seg;
void update(ll i, ll num) {
	i += h - 1;
	seg[i] = num;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}
// l, r 찾는 범위, num 현재 노드 번호, nl, nr 현재 범위
ll query(ll l, ll r, ll num, ll nl, ll nr) {
	if (l <= nl && nr <= r) return seg[num];
	if (nl > r || nr < l) return 0;

	int mid = (nl + nr) / 2;
	return query(l, r, num * 2, nl, mid) + query(l, r, num * 2 + 1, mid + 1, nr);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (h < n) h <<= 1;
	seg.resize(h * 2);
	ll a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		update(i + 1, a);
	}
	for (int i = 0; i < m + k; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) update(b, c);
		else printf("%lld\n", query(b, c, 1, 1, h));
	}
	return 0;
}