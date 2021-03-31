#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 100005
int N, M, K, indegree[MAX], constrct[MAX];
vector<vector<int>> adj;

int main(void) {
	scanf("%d%d%d", &N, &M, &K);
	adj.resize(N + 1);

	for (int i = 0, a, b; i < M; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 0, op, num; i < K; i++) {
		scanf("%d%d", &op, &num);

		if (op == 1) { // 건설
			if (indegree[num] <= 0) {
				constrct[num]++;
				if (constrct[num] == 1) { // 처음 건설할 때
					for (auto e : adj[num]) {
						--indegree[e];
					}
				}
			}
			else {
				printf("Lier!"); return 0;
			}
		}
		else { // 파괴
			if (constrct[num]) { // 삭제 가능
				constrct[num]--;
				if (constrct[num] == 0) {
					for (auto e : adj[num]) {
						++indegree[e];
					}
				}
			}
			else {
				printf("Lier!"); return 0;
			}
		}
	}
	printf("King-God-Emperor");
	return 0;
}