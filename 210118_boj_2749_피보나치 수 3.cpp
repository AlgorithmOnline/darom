#include <iostream>
using namespace std;
long long d[1500000];
int main() {
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i < 1500000; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 1000000;
	}

	long long n;
	cin >> n;
	cout << d[n % 1500000] << '\n';

	return 0;
}