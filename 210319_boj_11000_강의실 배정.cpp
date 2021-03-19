#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<pair<int, int>> room;
int main() {
	scanf("%d", &n);
	for (int i = 0, a, b; i < n; i++) {
		scanf("%d %d", &a, &b);
		room.push_back({ a, b });
	}
	sort(room.begin(), room.end());
	priority_queue<int> q;
	q.push(-room[0].second);
	for (int i = 1; i < room.size(); i++) {
		int ed = -q.top();
		if (ed > room[i].first) {
			q.push(-room[i].second);
		}
		else {
			q.pop();
			q.push(-room[i].second);			
		}
	}
	printf("%d", q.size());
	return 0;
}