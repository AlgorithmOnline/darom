#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int sumA[1005], sumB[1005]; // 누적합
int main() {
	int s, n, m;
	scanf("%d%d", &s, &n);
	for (int i = 1, a; i <= n; i++) {
		scanf("%d", &a);
		sumA[i] = sumA[i - 1] + a;
	}
	scanf("%d", &m);
	for (int i = 1, b; i <= m; i++) {
		scanf("%d", &b);
		sumB[i] = sumB[i - 1] + b;
	}
	vector<int> a, b; // 나올수 있는 부분 합 - 누적합 활용
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			a.push_back(sumA[j] - sumA[i - 1]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			b.push_back(sumB[j] - sumB[i - 1]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	auto l = a.begin(), r = b.end() - 1;
	ll sum = *l + *r, ans = 0;
	while (l != a.end() && r >= b.begin()) {
		if (sum == s) {
			auto pl = equal_range(a.begin(), a.end(), *l);
			auto pr = equal_range(b.begin(), b.end(), *r);
			ans += (pl.second - pl.first) * (pr.second - pr.first);
			l = pl.second;
			r = pr.first;
			if (r == b.begin()) break;
			--r;
			sum = *l + *r;
		}
		else if (sum > s) {
			if (r == b.begin()) break;
			sum -= *r;
			--r;
			sum += *r;
		}
		else {
			sum -= *l;
			++l;
			sum += *l;
		}
	}
	printf("%lld", ans);
	return 0;
}