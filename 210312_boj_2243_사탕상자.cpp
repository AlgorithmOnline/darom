#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<ll>seg;
int n, h = 1;
void update(int i, int val) {
	i += h - 1;
	seg[i] += val;
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}
ll query(int node, int nl, int nr, int num) {
	if (nr <= nl) return nl;

	int mid = (nl + nr) / 2;
	if (seg[node * 2] >= num) 
		return query(node * 2, nl, mid, num);
	return query(node * 2 + 1, mid + 1, nr, num - seg[node *2]);
}
int main() {
	scanf("%d", &n);
	while (h < 1000000) h <<= 1; //높이구하기 1 2 4 8
	seg.resize(h * 2);
	for (int i = 1, a, b, c; i <= n; i++) {
		scanf("%d", &a);
		if (a == 2) {
			scanf("%d %d", &b, &c);
			update(b, c);
		}
		else {
			scanf("%d", &b);
			ll number = query(1, 1, h, b);
			printf("%lld\n", number);
			update(number, -1);
		}
	}
	return 0;
}