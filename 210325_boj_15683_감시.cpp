#include <iostream>
#include <vector>
#include <cstring> // memcpy - string.h c++ 버전
#include <algorithm>
using namespace std;
const int MAX = 10;
typedef pair<int, int> p;
int n, m, arr[MAX][MAX], ans = 1e9;
int rotation[] = { -1, 4, 2, 4, 4, 1 };
vector<pair<int, p>> camera;

void check(int d, int x, int y) {
	d %= 4;

	switch (d) {
	case 0: // 동
		for (int j = y + 1; j < m; j++) {
			if (arr[x][j] == 6)	break;
			else if (!arr[x][j]) arr[x][j] = -1;
		}
		break;

	case 1: // 남
		for (int i = x + 1; i < n; i++) {
			if (arr[i][y] == 6) break;
			else if (!arr[i][y]) arr[i][y] = -1;
		}
		break;

	case 2: // 서
		for (int j = y - 1; j >= 0; j--) {
			if (arr[x][j] == 6)	break;
			else if (!arr[x][j]) arr[x][j] = -1;
		}
		break;
	default: // 북
		for (int i = x - 1; i >= 0; i--) {
			if (arr[i][y] == 6) break;
			else if (!arr[i][y]) arr[i][y] = -1;
		}
		break;
	}
}

void go(int idx) {
	if (idx == camera.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!arr[i][j]) cnt += 1;
			}
		}
		ans = min(ans, cnt);
		return;
	}
	int tmp[MAX][MAX] = { 0 };
	int num = camera[idx].first;
	int x = camera[idx].second.first, y = camera[idx].second.second;
	for (int i = 0; i < rotation[num]; i++) {
		memcpy(tmp, arr, sizeof(arr));

		switch (num) {
		case 1:
			check(i, x, y);
			break;
		case 2:
			check(i, x, y);
			check(i + 2, x, y);
			break;
		case 3:
			check(i, x, y);
			check(i + 1, x, y);
			break;
		case 4:
			check(i, x, y);
			check(i + 1, x, y);
			check(i + 2, x, y);
			break;
		case 5:
			check(i, x, y);
			check(i + 1, x, y);
			check(i + 2, x, y);
			check(i + 3, x, y);
			break;
		}
		go(idx + 1);
		memcpy(arr, tmp, sizeof(tmp));
	}
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				camera.push_back({ arr[i][j], { i, j } });
			}
		}
	}

	go(0);
	printf("%d", ans);

	return 0;
}