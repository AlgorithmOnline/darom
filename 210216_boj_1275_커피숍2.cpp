#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<ll>seg;
int n, m;
int h = 1;
void update(int i, int val) {
	i += h - 1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}
ll query(int l, int r, int num, int nl, int nr) {
	if (l <= nl && nr <= r) return seg[num];
	else if (nl > r || nr < l) return 0;
	int mid = (nl + nr) / 2;
	return query(l, r, num * 2, nl, mid) + query(l, r, num * 2 + 1, mid + 1, nr);
}
int main() {
	scanf("%d %d", &n, &m);
	while (h < n) h <<= 1;
	seg.resize(h * 2);
	for (int i = 0, num; i < n; i++) {
		scanf("%d", &num);
		update(i + 1, num);
	}
	for (int i = 0, a, b, c, d; i < m; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a > b) swap(a, b);
		printf("%lld\n", query(a, b, 1, 1, h));
		update(c, d);
	}
	return 0;
}