#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

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
	if (i > end || i < start) { // i > end일 때 node의 크기가 MAX를 넘어섬
		return;
	}
	tree[node] = max(tree[node], value);
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, i, value);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, value);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int h = (int)ceil(log2(MAX));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		int cur = maximum(tree, 1, 1, MAX, 1, num - 1);
		if (ans < cur + 1) {
			ans = cur + 1;
		}
		update(tree, 1, 1, MAX, num, cur + 1);
	}
	printf("%d\n", ans);
	return 0;
}