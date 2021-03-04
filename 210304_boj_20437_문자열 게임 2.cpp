#include <cstdio>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int t, k;
long long int ans;
char str[100005];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s %d", &str, &k);
		queue<int> q[30];
		int min_len = 1e9, max_len = 0;
		for (int i = 0; i < strlen(str); i++) {
			int num = str[i] - 'a';
			q[num].push(i);
			if (q[num].size() > k) q[num].pop();	
			if (q[num].size() == k) {
				min_len = min(min_len, q[num].back() - q[num].front() + 1);
				max_len = max(max_len, q[num].back() - q[num].front() + 1);
			}
		}
		if (!max_len) printf("-1\n");
		else printf("%d %d\n", min_len, max_len);
	}

	return 0;
}