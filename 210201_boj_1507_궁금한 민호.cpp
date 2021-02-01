#include <iostream>
using namespace std;
int d[20][20];
bool unused[20][20];
// 가능한 원래 존재하는 간선을 쓰는 것이 최소 개수
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (i == k) continue;
			for (int j = 0; j < n; j++) {
				if (i == j || k == j) continue;
				if (d[i][j] > d[i][k] + d[k][j]) { // 불가능한 경우(이미 완전한 플루이드이기 때문에)
					printf("-1"); 
					return 0;
				}
				if (d[i][j] == d[i][k] + d[k][j]) { // 대체 가능하므로 간선을 지움
					unused[i][j] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (unused[i][j] == false) {
				ans += d[i][j];
			}
		}
	}
	// 문제의 도로는 양방향이기 때문에 /2
	printf("%d", ans / 2);
	return 0;
}