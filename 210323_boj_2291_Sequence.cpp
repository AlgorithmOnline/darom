#include <iostream>
using namespace std;
long long d[11][221][221]; // len, sum, last
int n, m;
void go(int len, int sum, int last, long long cnt) {
	if (len <= 0) {
		return;
	}
	// cerr << len << ' ' << sum << ' ' << last << '\n';
	long long acc = 0;
	for (int i = last; i <= m; i++) {
		if (cnt < acc + d[len][sum][i]) {
			printf("%d ", i);
			go(len - 1, sum - i, i, cnt - acc);
			break;
		}
		acc += d[len][sum][i];
	}
}
int main() {
	long long s;
	scanf("%d%d%lld", &n, &m, &s);
	for (int i = 1; i <= m; i++) {
		d[1][i][i] = 1LL;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= j; k++) {
				for (int l = k; l <= j; l++) {
					if (j - k >= 1) {
						d[i][j][k] += d[i - 1][j - k][l];
					}
				}
			}
		}
	}
	go(n, m, 1, s - 1);
	return 0;
}