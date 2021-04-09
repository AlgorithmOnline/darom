#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int arr[105][105];
int n, K, L, i, idx, tail_idx, dir, tail_dir; //idx 는 turn 의 인덱스 번호, dir 은 머리 방향, tail_dir은 꼬리 방향
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
pair<int, char> turn[105];
pair<int, int> tail;
// 사과는 1, 뱀은 2, 아무것도 없으면 0
int main(){	
	scanf("%d %d", &n, &K);
	for (int i = 0, a, b; i < K; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1; // 사과
	}
	scanf("%d", &L);
	int X; char C;
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &X, &C);
		turn[i] = { X, C };
	}
	int r = 1, c = 1, sec = 0, cnt = 0;
	arr[1][1] = 2;
	tail = { 1,1 };
	while (r >= 1 && r <= n && c >= 1 && c <= n) {
		int tf = turn[idx].first;	char ts = turn[idx].second;
		
		r = r + dx[dir]; c = c + dy[dir];
		sec++;
		if (arr[r][c] == 2) {
			break;
		}
		if (!arr[r][c]) { // 꼬리가 위치한 칸을 당겨준다.
			cnt++;
			arr[tail.first][tail.second] = 0;
			tail.first = tail.first + dx[tail_dir]; tail.second = tail.second + dy[tail_dir];
		}
		if (sec == tf) { // 머리 방향전환
			dir = ts == 'L' ? (dir + 3) % 4 : (dir + 1) % 4;
			idx++;
		}
		if (cnt == turn[tail_idx].first) { // 꼬리 방향전환
			tail_dir = turn[tail_idx].second == 'L' ? (tail_dir + 3) % 4 : (tail_dir + 1) % 4;
			tail_idx++;
		}		
		arr[r][c] = 2;
	}
	printf("%d", sec);
	return 0;
}