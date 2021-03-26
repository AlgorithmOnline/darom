#include<iostream>
#include<vector>
#include<map>
#define MAX 55
using namespace std;
int N, M, K, ans;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
struct Fireball {
	int r, c, m, s, d;
};
vector<Fireball> fireball;

int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0, r, c, m, s, d; i < M; i++) {
		scanf("%d%d%d%d%d", &r, &c, &m, &s, &d);
		fireball.push_back({ r - 1, c - 1, m, s, d });
	}
	while (K--) {
		int size = fireball.size();
		map<pair<int, int>, vector<Fireball>> nFireball;
		while (size--) { // 이동
			int x = fireball[size].r;
			int y = fireball[size].c;
			int m = fireball[size].m;
			int s = fireball[size].s;
			int d = fireball[size].d;

			int nx = (x + dx[d] * s) % N;
			int ny = (y + dy[d] * s) % N;
			if (nx < 0) nx += N;
			if (ny < 0) ny += N;
			fireball[size].r = nx;
			fireball[size].c = ny;
			nFireball[{ nx, ny }].push_back(fireball[size]);
		}
		// 같은 칸에 있는지 확인 후 합치기
		fireball.clear();
		for (auto e : nFireball){
			if (e.second.size() > 1) { // 합치기
				int sum_m = 0, sum_s = 0;
				int sum_even = 0, sum_odd = 0;
				for (auto ele : e.second) {
					sum_m += ele.m;
					sum_s += ele.s;
					if (ele.d % 2) sum_odd++;
					else sum_even++;
				}
				int m = sum_m / 5;
				int s = sum_s / e.second.size();
				if (m == 0) continue;
				if (sum_even == e.second.size() || sum_odd == e.second.size()) { // 0, 2, 4, 6
					for(int i= 0; i < 7; i+=2)
						fireball.push_back({ e.first.first, e.first.second, m, s, i });
				}
				else { // 1, 3, 5, 7					
					for (int i = 1; i <= 7; i += 2)
						fireball.push_back({ e.first.first, e.first.second, m, s, i });
				}
			}
			else fireball.push_back({ e.second[0] });
		}
	}
	for (int i = 0; i < fireball.size(); i++) {
		ans += fireball[i].m;
	}
	// 질량의 합
	printf("%d", ans);

	return 0;
}