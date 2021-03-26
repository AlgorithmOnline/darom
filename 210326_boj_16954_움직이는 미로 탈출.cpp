#include<iostream>
#include<vector>
#include<queue>
#define MAX 10
using namespace std;
int n, chk[MAX][MAX];
char arr[MAX][MAX];
int dx[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dy[] = { 1, 0 ,-1 ,0, -1, 1 , 1, -1 };

int main(void) {
	for (int i = 0; i < 8; i++) {
		scanf("%s", &arr[i]);
	}
	queue<pair<int, int>> Q;
	Q.push({ 7, 0 });
	chk[7][0] = 1;
	bool flg = true;
	while (flg) {
		queue<pair<int, int>> q = Q;
		int size = q.size();
		while (size--){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (arr[x][y] == '#') continue;
			if (x == 0 && y == 7) { flg = false; break; }

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || arr[nx][ny] == '#') continue; //  || chk[nx][ny] 제외해야 맞음
				chk[nx][ny] = 1;
				q.push({ nx, ny });
			}
			q.push({ x, y });
		}
		Q = q;
		if (Q.empty()) break;

		for (int i = 7; i > 0; i--) {
			for (int j = 0; j < 8; j++) {
				arr[i][j] = arr[i - 1][j];
			}
		}
		for (int j = 0; j < 8; j++) {
			arr[0][j] = '.';
		}
	}
	
	printf("%d", chk[0][7]);

	return 0;
}