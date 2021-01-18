#include <cstdio>
long long d[2501];
long long m = 1000000007ll;
int main() {
	d[0] = 1;
	for (int i = 1; i <= 2500; i++) {
		d[i] = 0;
		for (int j = 0; j < i; j++) {
			d[i] += d[j] * d[i - 1 - j];
			d[i] %= m;
		}
		d[i] %= m;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", n % 2 == 0 ? d[n / 2] : 0);
	}
	return 0;
}