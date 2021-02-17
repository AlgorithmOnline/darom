#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<ll>seg;
int idx[200005];
int t, n, m, top;
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
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		while (h < n + m) h <<= 1; //높이구하기 1 2 4 8
		seg.resize(h * 2);
		for (int i = 0; i < n; i++) {
			update(i + 1, 1);
		}
		for (int i = 1, j = 0; i <= n; i++, j++) {
			idx[i] = n - j;
		}
		top = n;
		for (int i = 0, a; i < m; i++) {
			scanf("%d", &a);
			printf("%lld ", query(idx[a] + 1, top, 1, 1, h));
			update(idx[a], 0);
			idx[a] = ++top;
			update(idx[a], 1);
		}
		puts("");
		seg.clear();
		memset(idx, 0, sizeof(idx));
	}
	return 0;
}