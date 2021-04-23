#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int N, M, dp[55][55];;
char arr[55][55];
bool chk[55][55];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int go(int r, int c) {	
	if (r < 0 || r >= N || c < 0 || c >= M || arr[r][c] == 'H') return 0;
	if (chk[r][c]) {
		printf("-1"); exit(0);
	}
	int &ret = dp[r][c];
	if (ret != -1) return ret;
	
	chk[r][c] = true;
	ret = 0;
	int num = arr[r][c] - '0';
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i]*num, nc = c + dy[i]*num;
		ret = max(ret, go(nr, nc) + 1);
	}
	chk[r][c] = false;
	return ret;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i][0]);
	}
	// 가장 왼쪽 위가 시작지점
	memset(dp, -1, sizeof(dp));
	printf("%d", go(0, 0));
	return 0;
}