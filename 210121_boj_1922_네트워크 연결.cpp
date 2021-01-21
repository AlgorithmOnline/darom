#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
vector<p> adj[1001];
bool chk[1001];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c); // a, b, cost
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	chk[1] = true;
	priority_queue<p> q; // 내림차순이 기본이라 음수로 cost를 변환
	for (auto& e : adj[1]) {
		q.push({ -e.second, e.first });
	}

	int ans = 0;
	while (!q.empty()) {
		auto front = q.top();
		q.pop();
		if (chk[front.second]) continue;
		chk[front.second] = true;
		ans += -front.first;
		int next = front.second;
		for (auto& e : adj[next]) {
			q.push({ -e.second, e.first });
		}
	}
	printf("%d", ans);
	return 0;
}