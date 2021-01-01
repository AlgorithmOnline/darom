#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
map<int, int> dist; // 최소 이동 횟수
int main() {
	int n = 3;
	int start = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 0) { // 항상 9자리 수로 만들기 위함
				tmp = 9;
			}
			start = start * 10 + tmp; // 3 * 3 표를 1행 짜리 정수로 저장
		}
	}
	queue<int> q;	
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int now_num = q.front();
		string now = to_string(now_num);
		q.pop();
		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				string next = now;
				swap(next[x * 3 + y], next[nx * 3 + ny]);
				int num = stoi(next);
				if (dist.count(num) == 0) {
					dist[num] = dist[now_num] + 1;
					q.push(num);
				}
			}
		}
	}
	if (dist.count(123456789) == 0) {
		printf("-1");
	}
	else {
		printf("%d", dist[123456789]);
	}
	return 0;
}