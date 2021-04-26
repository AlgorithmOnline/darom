#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool chk[101][101];
char str[101][101];

void dfs(int x, int y, int flg) {
	chk[x][y] = true;
	char c = str[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || chk[nx][ny]) continue;
		if (flg && (c == 'R' || c == 'G') && (str[nx][ny] == 'R' || str[nx][ny] == 'G')) {
			chk[nx][ny] = true;
			dfs(nx, ny, flg);			
		}
		else if (c == str[nx][ny]) {
			chk[nx][ny] = true;
			dfs(nx, ny, flg);
		}		
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str[i]);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!chk[i][j]) {
				dfs(i, j, 0);
				cnt++;
			}
		}
	}
	printf("%d ", cnt);
	cnt = 0;
	memset(chk, false, sizeof(chk));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!chk[i][j]) {
				dfs(i, j, 1);
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}