#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int sumA[3010], sumB[3010], ans; // 누적합
int main() {
	int s, n, m;
	scanf("%d%d%d", &s, &n, &m);
	for (int i = 1, a; i <= n; i++) {
		scanf("%d", &a);
		sumA[i] = sumA[i - 1] + a;
	}
	for (int i = n + 1; i <= n * 2; i++) // n -> 1 -> 2 -> 3 ... 누적합구해줌
		sumA[i] = sumA[i - n] + sumA[n];
	for (int i = 1, b; i <= m; i++) {
		scanf("%d", &b);
		sumB[i] = sumB[i - 1] + b;
	}
	for (int i = m + 1; i <= m * 2; i++) // n -> 1 -> 2 -> 3 ... 누적합구해줌
		sumB[i] = sumB[i - m] + sumB[m];

	vector<int> a, b; // 나올수 있는 부분 합 - 누적합 활용
	for (int i = 1; i <= n; i++) {
		for (int j = i; j < i + n - 1; j++) {
			a.push_back(sumA[j] - sumA[i - 1]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j < i + m - 1; j++) {
			b.push_back(sumB[j] - sumB[i - 1]);
		}
	}
	a.push_back(sumA[n]); b.push_back(sumB[m]);
	a.push_back(0); b.push_back(0);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i <= s; i++) {
		auto p1 = equal_range(a.begin(), a.end(), i);
		auto p2 = equal_range(b.begin(), b.end(), s - i);
		ans += (p1.second - p1.first) * (p2.second - p2.first);
	}
	printf("%d", ans);
	return 0;
}