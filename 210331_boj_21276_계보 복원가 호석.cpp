#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 1005
map<string, int> idx;
vector<vector<int>> adj(MAX);
vector<string> v;
vector<vector<int>> children(MAX);
int N, M, indegree[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s; cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) idx[v[i]] = i;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string a, b;
		cin >> a >> b;
		int u = idx[a];
		int v = idx[b];
		adj[v].push_back(u);
		indegree[u]++;
	}

	queue<int> q;
	vector<int> ans;
	for (int i = 0; i < N; ++i) {
		if (indegree[i] == 0) {
			ans.push_back(i);
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int nxt : adj[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0) {
				children[cur].push_back(nxt);
				q.push(nxt);
			}
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans) cout << v[i] << ' ';
	cout << '\n';
	for (int i = 0; i < N; ++i) {
		cout << v[i] << ' ' << children[i].size() << ' ';
		sort(children[i].begin(), children[i].end());
		for (int j : children[i]) cout << v[j] << ' ';
		cout << '\n';
	}
	return 0;
}