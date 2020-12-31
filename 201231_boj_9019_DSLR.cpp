#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
bool chk[10001];
int dist[10001];
int from[10001];
char how[10001];
char command[] = { 'D','S','L','R' };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		memset(chk, false, sizeof(chk));
		memset(dist, 0, sizeof(dist));
		memset(how, 0, sizeof(how));
		memset(from, 0, sizeof(from));
		chk[a] = true;
		dist[a] = 0;
		from[a] = -1;
		queue<int> q;
		q.push(a);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			int next = 0;
			for (int i = 0; i < 4; i++) {
				if(i == 0) next = (now * 2) % 10000; // D
				else if (i == 1) { // S
					next = now - 1;
					if (next == -1) next = 9999;
				}
				else if(i ==2) next = (now % 1000) * 10 + now / 1000; // L
				else next = (now / 10) + (now % 10) * 1000; // R

				if (chk[next] == false) {
					q.push(next);
					chk[next] = true;
					dist[next] = dist[now] + 1;
					from[next] = now;
					how[next] = command[i];
				}
			}
		}
		string ans = "";
		while (a != b) {
			ans += how[b];
			b = from[b];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	return 0;
}