#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100001
using namespace std;

int n, cost = 0;
struct Planet {
	int idx, x, y, z;
};
bool cmpx(Planet a, Planet b) {
	return a.x < b.x;
}
bool cmpy(Planet a, Planet b) {
	return a.y < b.y;
}
bool cmpz(Planet a, Planet b) {
	return a.z < b.z;
}
struct Tunnel {
	int i, j, w;
	bool operator < (const Tunnel& t) const {
		return w < t.w;
	}
};
Planet planet[MAX];
vector<Tunnel> tunnel;
int vRoot[MAX];

int findRoot(int v) {
	if (vRoot[v] == v) return v;
	return vRoot[v] = findRoot(vRoot[v]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> planet[i].x >> planet[i].y >> planet[i].z;
		planet[i].idx = i;
		vRoot[i] = i;
	}
	sort(planet + 1, planet + n + 1, cmpx);
	for (int i = 1; i <= n - 1; i++) {
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].x - planet[i + 1].x) });
	}
	sort(planet + 1, planet + n + 1, cmpy);
	for (int i = 1; i <= n - 1; i++) {
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].y - planet[i + 1].y) });
	}
	sort(planet + 1, planet + n + 1, cmpz);
	for (int i = 1; i <= n - 1; i++) {
		tunnel.push_back({ planet[i].idx, planet[i + 1].idx, abs(planet[i].z - planet[i + 1].z) });
	}
	sort(tunnel.begin(), tunnel.end());
	for (Tunnel t : tunnel) {
		int rootI = findRoot(t.i);
		int rootJ = findRoot(t.j);
		if (rootI != rootJ) {
			vRoot[rootJ] = rootI;
			cost += t.w;
		}
	}
	cout << cost << '\n';

	return 0;
}