#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n, parent[200001], cnt[200001];
char s1[21], s2[21];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

int Union(int x, int y) {
	x = Find(x); y = Find(y);

	if (x != y) {
		parent[x] = y;
		cnt[y] += cnt[x];
		cnt[x] = 1;
	}
	return cnt[y];
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int count = 1;
		map<string, int> num;
		scanf("%d", &n);
		for (int i = 1; i <= (2 * n); i++) {
			parent[i] = i;
			cnt[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			scanf("%s %s", &s1, &s2);
			if (!num[s1]) num[s1] = count++;
			if (!num[s2]) num[s2] = count++;
			printf("%d\n", Union(num[s1], num[s2]));
		}
	}

	return 0;
}