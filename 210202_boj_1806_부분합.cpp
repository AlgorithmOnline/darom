#include <cstdio>
#include <vector>
using namespace std;
int a[100001];
int main() {
	int n, s;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int left = 0, right = 0;
	int sum = a[0], ans = n + 1;
	while (left <= right && right < n) {
		if (sum < s) {
			right += 1;
			sum += a[right];
		}
		else if (sum == s) {
			if (right - left + 1 < ans) {
				ans = right - left + 1;
			}
			right += 1;
			sum += a[right];
		}
		else if (sum > s) {
			if (right - left + 1 < ans) { // S 이상이면 정답가능
				ans = right - left + 1;
			}
			sum -= a[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = a[left];
			}
		}
	}
	if (ans > n) ans = 0;
	printf("%d", ans);
	return 0;
}