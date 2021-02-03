#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<bool> chk(n + 1);
	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (chk[i] == false) {
			prime.push_back(i);
			for (int j = i * 2; j <= n; j += i) {
				chk[j] = true;
			}
		}
	}

	int l = 0, r = 0;
	int sum = prime.empty() ? 0 : prime[0];
	int ans = 0;
	while (l <= r && r < prime.size()) {
		if (sum <= n) {
			if (sum == n) {
				ans += 1;
			}
			r++;
			if (r < prime.size()) {
				sum += prime[r];
			}
		}
		else {
			sum -= prime[l++];
		}
	}
	printf("%d", ans);
	return 0;
}