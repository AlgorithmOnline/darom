#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
int dist[101][101], visit[101][101];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			dist[i][j] = INF;
		}
	}
	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		dist[x][y] = min(dist[x][y], z);
		visit[x][y] = y; // x 에서 y로 부터가는 간선(y를 거친다)
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					visit[i][j] = visit[i][k]; // 경로 추적(k를 거친다)
				}
			}
		}
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				printf("0\n"); continue;
			}			
			vector<int> ans;
			int st = i, end = j;
			while (st != 0) {
				ans.push_back(st);
				st = visit[st][end];
			}
			
			// 경로 수 출력
			printf("%d ", ans.size());
			for (int k = 0; k < ans.size(); k++) {
				printf("%d ", ans[k]);
			}
			printf("\n");
		}
	}

	return 0;
}