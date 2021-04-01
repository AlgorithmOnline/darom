#include <cstdio>
#include <vector>
using namespace std;
#define MAX 100005
int n, m, sum[MAX];
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1, a; i <= n; i++) {
		scanf("%d", &a);
		sum[i] = sum[i - 1] + a;
	}
	for (int i = 0, st, ed; i < m; i++) {
		scanf("%d %d", &st, &ed);
		printf("%d\n", sum[ed] - sum[st - 1]);
	}
	return 0;
}