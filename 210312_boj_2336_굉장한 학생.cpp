#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
typedef pair<int, pair<int, int>> Pair;
typedef long long int ll;
#define inf 987654321
vector<ll>seg;
vector<Pair> v;
int n;
int h = 1;
int ans;
bool cmp(Pair a, Pair b) {
	return make_tuple(a.first, a.second.first, a.second.second) < make_tuple(b.first, b.second.first, b.second.second);
}

void update(int i, int val) {
	i += h - 1;
	seg[i] = val;
	while (i > 1) {
		i /= 2;
		seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
	}
}
ll query(int l, int r, int num, int nl, int nr) {
	//l,r이 찾으려는 범위, num이 현재 보고 있는 노드
	//nl,nr 현재 보고있는 범위
	if (l <= nl && nr <= r)return seg[num];
	else if (nl > r || nr < l)return inf;
	int mid = (nl + nr) / 2;
	return min(query(l, r, num * 2, nl, mid), query(l, r, num * 2 + 1, mid + 1, nr));
}
int main() {
	scanf("%d", &n);
	while (h < n)h <<= 1; //높이구하기 1 2 4 8
	seg.resize(h * 2);
	v.resize(n + 1);
	fill(seg.begin(), seg.end(), inf);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			if (i == 0)
				v[num].first = j + 1;
			else if (i == 1)
				v[num].second.first = j + 1;
			else if (i == 2)
				v[num].second.second = j + 1;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i <= n; i++) {
		update(v[i].second.first, v[i].second.second);
		ll val = query(1, v[i].second.first - 1, 1, 1, h);
		if (val == inf || val > v[i].second.second)ans++;
	}
	printf("%d\n", ans);
	return 0;
}