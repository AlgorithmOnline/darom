#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define mod 1000000007
vector<long long int>seg;
int n, m, k;
int h = 1;
void update(int i, int val) {
	i += h - 1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = (seg[i * 2] * seg[i * 2 + 1]) % mod;
	}
}
long long int query(int l, int r, int num, int nl, int nr) {
	//l,r이 찾으려는 범위, num이 현재 보고 있는 노드
	//nl,nr 현재 보고있는 범위
	if (l <= nl && nr <= r) return seg[num];
	else if (nl > r || nr < l) return 1;
	int mid = (nl + nr) / 2;
	return (query(l, r, num * 2, nl, mid) * query(l, r, num * 2 + 1, mid + 1, nr)) % mod;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	while (h < n) h <<= 1; //높이구하기 1 2 4 8
	seg.resize(h * 2);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		update(i + 1, num);
	}
	for (int i = 0, a, b, c; i < m + k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) update(b, c);
		else printf("%lld\n", query(b, c, 1, 1, h));
	}
	return 0;
}