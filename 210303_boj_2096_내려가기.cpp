#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;
int n, dp1[2][5], dp2[2][5];
int main() {	
	scanf("%d", &n);
	fill(dp2[0], dp2[2], inf);
	for (int i = 1; i <= 3; i++) {
		scanf("%d", &dp1[0][i]);
		dp2[0][i] = dp1[0][i];
	}	
	int pre = 0, cur = 1;
	for (int i = 2; i <=  n; i++) {
		for (int j = 1, a; j <= 3; j++) {
			scanf("%d", &a);
			dp1[cur][j] = max(dp1[pre][j - 1], max(dp1[pre][j], dp1[pre][j + 1])) + a;
			dp2[cur][j] = min(dp2[pre][j - 1], min(dp2[pre][j], dp2[pre][j + 1])) + a;
		}
		pre ^= 1;
		cur ^= 1;
	}
	int MAX = max(dp1[pre][1], max(dp1[pre][2], dp1[pre][3]));
	int MIN = min(dp2[pre][1], min(dp2[pre][2], dp2[pre][3]));
	printf("%d %d", MAX, MIN);
	return 0;
}