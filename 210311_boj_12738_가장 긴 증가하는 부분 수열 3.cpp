#include <cstdio>
#include <map>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
int maximum(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return max(maximum(tree, node * 2, start, (start + end) / 2, left, right), maximum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
void update(vector<int>& tree, int node, int start, int end, int i, int value) {
	if (i > end || i < start) {
		return;
	}
	tree[node] = max(tree[node], value);
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, i, value);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, value);
	}
}
const int MAX = 1000000;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	map<int, int> d;
	for (int i = 0; i < b.size(); i++) {
		d[b[i]] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		a[i] = d[a[i]];
	}
	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int num = a[i];
		int cur = maximum(tree, 1, 1, MAX, 1, num - 1);
		if (ans < cur + 1) {
			ans = cur + 1;
		}
		update(tree, 1, 1, MAX, num, cur + 1);
	}
	printf("%d\n", ans);
	return 0;
}