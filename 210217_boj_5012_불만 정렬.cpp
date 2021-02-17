#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
vector<ll> lseg;
vector<ll> rseg;
int cnt[100005];
int arr[100005];
int n;
long long ans;
int h = 1;
void update(int i, int val, int k) {
	i += h - 1;
	vector<ll>& seg = k == 0 ? lseg : rseg;
	if (!k) seg[i] = val; // lseg
	else seg[i] += 1; // rseg
	while (i > 1) {
		i /= 2;
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}

}
long long int query(int l, int r, int num, int nl, int nr, int k) {
	vector<ll>& seg = k == 0 ? lseg : rseg;
	if (l <= nl && nr <= r) return seg[num];
	else if (nl > r || nr < l) return 0;
	int mid = (nl + nr) / 2;
	return query(l, r, num * 2, nl, mid, k) + query(l, r, num * 2 + 1, mid + 1, nr, k);
}
int main() {
	scanf("%d", &n);
	while (h < n)h <<= 1; //높이구하기 1 2 4 8
	lseg.resize(h * 2);
	rseg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		cnt[arr[i]]++;
		update(arr[i], cnt[arr[i]], 0);
	}
	for (int i = n; i > 0; i--) { 
		ans += query(arr[i] + 1, n, 1, 1, h, 0) * query(1, arr[i] - 1, 1, 1, h, 1);
		update(arr[i], cnt[arr[i]] - 1, 0);
		update(arr[i], 1, 1);
		cnt[arr[i]]--;
	}
	printf("%lld", ans);
	return 0;
}