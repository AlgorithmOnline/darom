#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] %= m;
	}
	vector<long long> cnt(m, 0);
	cnt[0] = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		sum %= m;
		cnt[sum] += 1;
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) { // cnt[i]개 중 2개를 고르는 콤비네이션
		ans += (long long)cnt[i] * (long long)(cnt[i] - 1) / 2LL;
	}
	printf("%lld", ans);

	return 0;
}