#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define mod 1000000007
typedef long long int ll;
ll n;
map<ll, ll> m;
ll fibonacci(ll num) {
	if (num == 1) return 1;
	else if (num == 2) return 1;
	else if (m[num]) return m[num];
	else {
		if (num % 2) {
			ll t = (num + 1) / 2;
			ll Fn = fibonacci(t);
			ll Fn1 = fibonacci(t - 1);

			m[num] = (Fn * Fn + Fn1 * Fn1) % mod;
			return m[num];
		}
		else {
			ll t = num / 2;
			ll Fn1 = fibonacci(t - 1);
			ll Fn = fibonacci(t);

			m[num] = (2 * Fn1 + Fn) * Fn % mod;
			return m[num];
		}
	}
}
int main() {
	scanf("%lld", &n);

	printf("%lld", fibonacci(n));
	
	return 0;
}