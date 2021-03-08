#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> p;
int n;
long long int ans;
vector<p> v;
int main() {
	scanf("%d", &n);
	for (int i = 0, a, b; i < n; i++) {
		scanf("%d %d", &a, &b);
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	int st = v[0].first, ed = v[0].second;
	for (int i = 1; i < (int)v.size(); i++) {
		if (v[i].first > ed) {
			ans += ed - st;
			st = v[i].first, ed = v[i].second;
		}
		else ed = max(ed, v[i].second);
	}
	ans += ed - st;
	printf("%lld", ans);
	return 0;
}