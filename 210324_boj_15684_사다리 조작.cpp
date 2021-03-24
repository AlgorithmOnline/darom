#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 30;
int n, m, h, ladderCnt;
bool flag;
bool ladder[MAX][11];

void DFS(int a, int cnt) {
	//답을 찾았으므로
	if (flag) return;
	//기저 사례
	if (ladderCnt == cnt)	{
		bool possible = true;
		for (int i = 1; i <= n; i++) {
			int row = i;
			for (int j = 0; j < h; j++) {
				//오른쪽
				if (ladder[j][row])
					row++;
				//왼쪽
				else if (row > 1 && ladder[j][row - 1])
					row--;						
			}
			//i번 세로선의 결과가 i번이 나와야 한다		
			if (i != row) {
				possible = false;
				break;
			}
		}
		if (possible)
			flag = true;
		return;
	}

	for (int i = a; i < h; i++) {
		for (int j = 1; j < n; j++) {
			//두 가로선이 연속하거나 서로 접하면 안된다
			if (!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1]) {
				ladder[i][j] = true;
				DFS(i, cnt + 1);
				ladder[i][j] = false;
			}
		}
	}
	return;
}

int main(void) {
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		//(a-1)번째 행(위치)에서 b ~ (b+1) 세로선을 이어주는 사다리
		ladder[a - 1][b] = true;
	}
	for (int i = 0; i <= 3; i++) {
		ladderCnt = i; // 목표
		DFS(0, 0);
		if (flag) {
			printf("%d", ladderCnt);
			return 0;
		}
	}
	printf("-1");
	return 0;
}