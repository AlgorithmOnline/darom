#include<stdio.h>
#include<memory.h>

int ans, N, i, j;
struct board {
	int arr[20][20];
	void r90() {
		int tmp[20][20];
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				tmp[i][j] = arr[N - j - 1][i];
			}
		}
		memcpy(arr, tmp, sizeof(arr));
	}
	void up() {
		int tmp[20][20];
		for (i = 0; i < N; i++) {
			int c = -1, d = 0;
			for (j = 0; j < N; j++) {
				if (arr[i][j] == 0);
				else if (d && arr[i][j] == tmp[i][c]) tmp[i][c] *= 2, d = 0;
				else tmp[i][++c] = arr[i][j], d = 1;
			}
			for (c++; c < N; c++) tmp[i][c] = 0;
		}
		memcpy(arr, tmp, sizeof(arr));
	}
	void max_value() {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (ans < arr[i][j]) ans = arr[i][j];
			}
		}
	}
};

void dfs(board c, int cnt) {
	if (cnt >= 5) {
		c.max_value();
		return;
	}

	for (int i = 0; i < 4; i++) {
		board d = c;
		d.up();
		dfs(d, cnt + 1);
		c.r90();
	}
}

int main() {
	board c;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) 
			scanf("%d", c.arr[i] + j);
	}
	dfs(c, 0);
	printf("%d\n", ans);
}