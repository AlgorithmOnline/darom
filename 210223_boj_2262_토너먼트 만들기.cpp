#include <iostream>
#include <algorithm>
using namespace std;
int d[256][256];
int a[256];
int w[256][256];
int go(int i, int j) {
	if (d[i][j]) return d[i][j];
	if (i == j) return 0;
	d[i][j] = 200000000;
	for (int k = i; k < j; k++) {
		int temp = go(i, k) + go(k + 1, j);
		temp += abs(w[i][k] - w[k + 1][j]);
		if (d[i][j] > temp) {
			d[i][j] = temp;
		}
	}
	return d[i][j];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		w[i][i] = a[i];
		for (int j = i + 1; j < n; j++) {
			w[i][j] = min(w[i][j - 1], a[j]);
		}
	}
	printf("%d", go(0, n - 1));
	return 0;
}