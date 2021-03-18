#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, k, ans = 100001;
int dist[100001], parent[100001];
int main() {
	scanf("%d%d", &n, &k);
	queue<int> q;
	q.push(n);
	dist[n] = 1; // 마지막 ans에 1빼줘야 함
	parent[n] = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == k) {
			if (ans > dist[k]) {
				ans = dist[k];
			}
			continue;
		}

		if (cur - 1 >= 0) {
			if (!dist[cur - 1] || dist[cur - 1] >= dist[cur] + 1) {
				dist[cur - 1] = dist[cur] + 1;
				parent[cur - 1] = cur;
				q.push(cur - 1);
			}
		}
		if (cur + 1 <= 100000) {
			if (!dist[cur + 1] || dist[cur + 1] >= dist[cur] + 1) {
				dist[cur + 1] = dist[cur] + 1;
				parent[cur + 1] = cur;
				q.push(cur + 1);
			}
		}
		if (cur * 2 <= 100000) {
			if (!dist[cur * 2] || dist[cur * 2] >= dist[cur] + 1) {
				dist[cur * 2] = dist[cur] + 1;
				parent[cur * 2] = cur;
				q.push(cur * 2);
			}
		}
	}
	printf("%d\n", ans - 1);
	int end = k;
	vector<int> ans;
	while (parent[end] != -1) {
		ans.push_back(end);
		end = parent[end];
	}
	ans.push_back(end);
	reverse(ans.begin(), ans.end());
	for (auto e : ans) {
		printf("%d ", e);
	}
	
	return 0;
}