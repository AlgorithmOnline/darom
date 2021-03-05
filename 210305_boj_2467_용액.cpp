#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int l = 0, r = n - 1;
	int Min = abs(v[l] + v[r]), x = v[l], y = v[r];
	while (l < r) {
		if (Min > abs(v[l] + v[r])) {
			Min = abs(v[l] + v[r]);
			x = v[l], y = v[r];
			if (!Min) break;
		}
		if (v[l] + v[r] > 0) r--;
		else l++;
	}
	printf("%d %d", x, y);
	return 0;
}