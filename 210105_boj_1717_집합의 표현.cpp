#include <iostream>
#include <algorithm>
using namespace std;

int n, m, parent[1000005];
int Find(int x) { // 경로 압축
	if (parent[x] < 0) return x;
	else return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	x = Find(x); y = Find(y);

	if (x == y) return;
	parent[x] += parent[y];
	parent[y] = x;
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i <= n; i++) {
		parent[i] = -1;
	}

	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		if (!a) {
			Union(b, c);
		}
		else {
			
			printf("%s\n", Find(b) == Find(c) ? "YES" : "NO");
		}
	}

	return 0;
}