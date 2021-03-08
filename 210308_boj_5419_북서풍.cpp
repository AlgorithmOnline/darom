#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZE = 1 << 18; // 75000*2 이상
typedef pair<int, int> p;
typedef long long int ll;
int t, n;

struct SegTree {
	int arr[SIZE];
	SegTree() { fill(arr, arr + SIZE, 0); }
	// n번째 리프 노드를 1 증가시킴
	void inc(int n) {
		n += SIZE / 2;
		while (n > 0) {
			arr[n]++;
			n /= 2;
		}
	}
	// 구간 [s, e)의 합
	int sum(int s, int e) { return sum(s, e, 1, 0, SIZE / 2); }
	int sum(int s, int e, int node, int ns, int ne) {
		if (e <= ns || ne <= s) return 0;
		if (s <= ns && ne <= e) return arr[node];
		int mid = (ns + ne) / 2;
		return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid, ne);
	}
};

bool cmp(p& a, p& b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<p> v;
		for (int i = 0, a, b; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ a, b });
		}

		// y좌표 오름차순으로 정렬
		sort(v.begin(), v.end(), [](p& a, p& b) {
			return a.second < b.second;
		});
		// y좌표가 -10억~ 10억 범위이기 때문에 세그먼트 트리 구성을 위해
		// 점 75000개에 대응되는 수로 변환한다.
		int newY[75000], range = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && v[i].second != v[i - 1].second) range++;
			newY[i] = range;
		}
		// 동시에 바꾸면 if문 비교 때 틀릴 수 있기 때문에 따로 변환
		for (int i = 0; i < n; i++) {
			v[i].second = newY[i];
		}

		// 점들을 차례대로 훑으면서 항해할 수 있는 점 개수 세기
		sort(v.begin(), v.end(), cmp);
		SegTree ST;
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += ST.sum(v[i].second, SIZE / 2);
			ST.inc(v[i].second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}