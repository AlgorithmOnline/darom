#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n;
int w[10001];
int d[10001][2];
vector<int> a[10001];
vector<int> ans;
void go(int now, int parent) {
	for (int i = 0; i < (int)a[now].size(); i++) {
		if (parent == a[now][i]) {
			continue;
		}
		go(a[now][i], now);
	}
	d[now][1] = w[now];
	d[now][0] = 0;
	for (int i = 0; i < (int)a[now].size(); i++) {
		if (parent == a[now][i]) {
			continue;
		}
		d[now][1] += d[a[now][i]][0];
		d[now][0] += max(d[a[now][i]][0], d[a[now][i]][1]);
	}
}
void gogo(int x, int y, int parent) {
	if (y == 0) {
		for (int i = 0; i < (int)a[x].size(); i++) {
			if (parent == a[x][i]) {
				continue;
			}
			if (d[a[x][i]][0] < d[a[x][i]][1]) {
				gogo(a[x][i], 1, x);
			}
			else {
				gogo(a[x][i], 0, x);
			}
		}
	}
	else if (y == 1) {
		ans.push_back(x);
		for (int i = 0; i < (int)a[x].size(); i++) {
			if (parent == a[x][i]) {
				continue;
			}
			gogo(a[x][i], 0, x);
		}
	}
}
int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d ", &w[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int t1, t2;
		scanf("%d %d\n", &t1, &t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	go(1, 0);
	printf("%d\n", max(d[1][0], d[1][1]));
	if (d[1][0] < d[1][1]) {
		gogo(1, 1, 0);
	}
	else {
		gogo(1, 0, 0);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}