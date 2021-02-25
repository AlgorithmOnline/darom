#include <iostream>
#include <vector>
using namespace std;
int n, m, parent[201];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x), y = Find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) { // 양방향
		for (int j = 1, a; j <= n; j++) {
			scanf("%d", &a);
			if (a) {
				Union(i, j);
			}
		}
	}

	int pre, next;
	scanf("%d", &pre);
	for (int i = 1; i < m; i++) {
		scanf("%d", &next);

		int x = Find(pre), y = Find(next);
		if (x != y) {
			printf("NO"); return 0;
		}
		pre = next;
	}
	printf("YES");
	return 0;
}