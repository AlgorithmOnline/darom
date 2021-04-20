#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { -1, -1, -1, 0, 0,1,1,1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
queue< pair<int, pair<int, int>>> tree_summer;
queue<pair<int, int>> tree_fall;
int N, M, K, food[11][11];
typedef struct Info {
	int plant_food; // 양분
	vector<int> tree; // 나무의 나이
};
Info arr[11][11];

// 봄에 죽은 나무가 양분 -> 죽은 나무마다 나이/2 한 값이 해당 칸에 양분으로 추가됨
void Summer() {
	while(!tree_summer.empty()) {
		int food = tree_summer.front().first;
		int x = tree_summer.front().second.first, y = tree_summer.front().second.second;
		tree_summer.pop();
		arr[x][y].plant_food += (food / 2);
	}
}
// 나무 나이만큼 양분을 먹음. 나이만큼 못먹으면 즉시 죽음
void Spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vector<int> &T = arr[i][j].tree;
			sort(T.begin(), T.end());
			vector<int> New;
			int size = T.size();
			int &pf = arr[i][j].plant_food;
			for (int k = 0; k < size; k++) {
				int tree = T[k];
				if ( pf - tree < 0) {
					tree_summer.push({ tree, {i, j} });
				}
				else {
					pf -= tree;
					New.push_back(++tree);
					if (tree % 5 == 0) { // 5의 배수인 칸이면 한그루만 번식하는건지 알아보기.
						tree_fall.push({ i, j });
					}
				}
			}
			T = New;
		}
	}
}
// 나무의 나이가 5배수인 나무가 번식. 인접한 8개의 칸에 나이가 1인 나무가 생김
void Fall() {	
	while (!tree_fall.empty()) {
		int x = tree_fall.front().first, y = tree_fall.front().second;
		tree_fall.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			arr[nx][ny].tree.push_back(1);
		}
	}
}
// 입력으로 주어진 양분을 땅에 추가
void Winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j].plant_food += food[i][j];
		}
	}
}

int CountTree() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += arr[i][j].tree.size();
		}
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &food[i][j]);
			arr[i][j].plant_food = 5; // 양분 초기화
		}
	}
	for (int i = 0, a, b, c; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		arr[a - 1][b - 1].tree.push_back(c);
	}
	
	while (K--) {
		Spring();
		Summer();
		Fall();
		Winter();
	}
	printf("%d", CountTree());
	return 0;
}