#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrix_multiplication(vector<vector<int>>& a, vector<vector<int>>& b) {
	int n = a.size();
	vector<vector<int>> c(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}
int main() {
	int n;
	long long b;

	scanf("%d%lld", &n, &b);

	vector<vector<int>> ans(n, vector<int>(n));
	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
		ans[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1) {
			ans = matrix_multiplication(ans, a);
		}
		a = matrix_multiplication(a, a);
		b /= 2;
	}

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}