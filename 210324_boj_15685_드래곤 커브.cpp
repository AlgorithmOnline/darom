#include<iostream>
#include<vector>
#define MAX 101
using namespace std;
int n, x, y, d, g, Sx, Sy;
int arr[MAX][MAX];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0 ,-1 ,0 };
vector<int> dir_info;

void Dragon_Curve() {
	int size = dir_info.size();
	for (int i = size - 1; i >= 0; i--) {
		int dir = (dir_info[i] + 1) % 4;
		x = x + dx[dir];
		y = y + dy[dir];
		arr[x][y] = 1;

		dir_info.push_back(dir);
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &y, &x, &d, &g);

		dir_info.clear();
		arr[x][y] = 1;
		x = x + dx[d];
		y = y + dy[d];
		arr[x][y] = 1;

		dir_info.push_back(d);
		for (int j = 0; j < g; j++) {
			Dragon_Curve();
		}
	}

	int cnt = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == true)
				cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}