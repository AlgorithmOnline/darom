#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int, int> p;
int n, k, cnt[21];
long long int ans;
char name[21];
int main() {
	scanf("%d%d", &n, &k);
	deque<p> q;
	for (int i = 0; i < n; i++) {
		scanf("%s", &name);
		if (!q.empty() && i - q.front().second > k) {
			cnt[q.front().first]--;
			q.pop_front();
		}
		int len = (int)strlen(name);
		ans += cnt[len]++;
		q.push_back({ len, i });
	}
	printf("%lld", ans);
	return 0;
}