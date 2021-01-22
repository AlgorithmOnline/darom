#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
int n, m, st, ed, ans;
int indegree[10001], dp[10001];
bool chk[10001];
vector<p> adj[10001];	// 인접리스트
vector<p> r_adj[10001]; // 그래프 역추적용 인접리스트
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b, c });
		indegree[b]++;
		r_adj[b].push_back({ a, c });
	}
	scanf("%d %d", &st, &ed);
	// 만나는 시간 구하기 - 위상정렬
	queue<p> q;
	q.push({ st, 0 });
	while (!q.empty()) {
		p front = q.front();
		q.pop();
		int num = front.first;
		for (auto next : adj[num]) {
			dp[next.first] = max(dp[next.first], dp[num] + next.second);
			if (--indegree[next.first] == 0) {
				q.push({ next.first, next.second });
			}
		}
	}
	// 도로의 수 구하기 - 그래프 역추적
	q.push({ ed, 0 });
	chk[ed] = true;
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int num = front.first;
		for (auto next : r_adj[num]) {
			if (dp[num] - dp[next.first] == next.second) {
				ans++;
				if (!chk[next.first]) {
					chk[next.first] = true;
					q.push({ next.first, next.second });
				}
			}
		}
	}
	printf("%d\n%d", dp[ed], ans);
	return 0;
}