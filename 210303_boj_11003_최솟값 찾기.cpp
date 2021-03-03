#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> p;
int n, l;
deque<p> q; // 값, 인덱스
int main() {	
	scanf("%d %d", &n, &l);
	vector<int> d(n);
	for (int i = 0, a; i < n; i++) {
		scanf("%d", &a);
		if (!q.empty() && l <= i - q.front().second) q.pop_front();
		while (!q.empty() && q.back().first > a) q.pop_back();
		q.push_back({ a, i });
		d[i] = q.front().first;
	}
	for (auto e : d)
		printf("%d ", e);

	return 0;
}