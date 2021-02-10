#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define INF (ll)1000000001
vector<ll> segmin;
vector<ll> segmax;
int n, m;
int h = 1;
void update(int i, int val, int k) {
	vector<ll>& s = k == 1 ? segmax : segmin;
	i += h - 1;
	s[i] = val;

	if (k == 1) {
		while (i > 1) {
			i /= 2;
			s[i] = max(s[i * 2], s[i * 2 + 1]);
		}
	}
	else {
		while (i > 1) {
			i /= 2;
			s[i] = min(s[i * 2], s[i * 2 + 1]);
		}
	}
}
long long int query(int l, int r, int num, int nl, int nr, int k) {
	//l,r이 찾으려는 범위, num이 현재 보고 있는 노드
	//nl,nr 현재 보고있는 범위
	vector<ll>& s = k == 1 ? segmax : segmin;
	if (l <= nl && nr <= r) return s[num];
	else if (nl > r || nr < l) {
		if (k == 0) return INF;
		else return 0;
	}

	int mid = (nl + nr) / 2;
	if (k == 1) {
		return max(query(l, r, num * 2, nl, mid, k), query(l, r, num * 2 + 1, mid + 1, nr, k));
	}
	else {
		return min(query(l, r, num * 2, nl, mid, k), query(l, r, num * 2 + 1, mid + 1, nr, k));
	}
}
int main() {

	scanf("%d %d", &n, &m);
	while (h < n)h <<= 1; //높이구하기 1 2 4 8
	segmin.resize(h * 2);
	segmax.resize(h * 2);
	fill(segmin.begin(), segmin.end(), INF);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		update(i + 1, num, 0);
		update(i + 1, num, 1);
	}
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%lld ", query(a, b, 1, 1, h, 0));
		printf("%lld\n", query(a, b, 1, 1, h, 1));
	}
	return 0;
}