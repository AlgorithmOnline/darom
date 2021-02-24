#include<iostream>
#include<vector>
#define MAX 20
using namespace std;

int n, m, sx, sy, k;
int arr[MAX][MAX];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int dice[7];
vector<int> cmd;

void RollThedice(int d)
{
	int d1, d2, d3, d4, d5, d6;
	d1 = dice[1], d2 = dice[2], d3 = dice[3];
	d4 = dice[4], d5 = dice[5], d6 = dice[6];

	if (d == 0) {			// 동
		dice[3] = d1;
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
	}
	else if (d == 1) {	// 서
		dice[4] = d1;
		dice[1] = d3;
		dice[3] = d6;
		dice[6] = d4;
	}
	else if (d == 2) {	// 북
		dice[2] = d1;
		dice[1] = d5;
		dice[5] = d6;
		dice[6] = d2;
	}
	else if (d == 3) {	// 남
		dice[6] = d5;
		dice[5] = d1;
		dice[1] = d2;
		dice[2] = d6;
	}
}

int main(void)
{
	scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &k);
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0, a; i < k; i++)
	{
		scanf("%d", &a);
		cmd.push_back(--a);
	}

	int x = sx;
	int y = sy;
	for (int i = 0; i < cmd.size(); i++) {
		int nx = x + dx[cmd[i]];
		int ny = y + dy[cmd[i]];
		int d = cmd[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		RollThedice(d);
		if (arr[nx][ny] == 0) arr[nx][ny] = dice[6];
		else {
			dice[6] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		printf("%d\n", dice[1]);
		x = nx;
		y = ny;
	}
	return 0;
}
