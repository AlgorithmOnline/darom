#include <cstdio>
#include <stack>
using namespace std;
typedef long long ll;
ll a[100000];
int n;
int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		stack<ll> s;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int left = i;
			while (!s.empty() && a[s.top()] > a[i]) {
				ll height = a[s.top()];
				s.pop();
				ll width = i;
				if (!s.empty()) {
					width = (i - s.top() - 1);
				}
				if (ans < width * height) {
					ans = width * height;
				}
			}
			s.push(i);
		}
		while (!s.empty()) {
			ll height = a[s.top()];
			s.pop();
			ll width = n;
			if (!s.empty()) {
				width = n - s.top() - 1;
			}
			if (ans < width * height) {
				ans = width * height;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}