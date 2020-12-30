#include <iostream>
using namespace std;
int n, m; // 인원 수, 놀이기구 수
int a[10001];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	if (n <= m) {
		printf("%d\n", n);
		return 0;
	}

	// x분까지 탄 학생의 수 --> m + x/a[i];
	// x분에 총 몇명의 학생이 탔는지를 구할 수 있음.--> (x분 % 놀이기구 운행시간(a[i]) == 0)
	// 따라서, x분에 탄 학생의 범위내에서 n이 있는지 확인하고 이분탐색을 함.
	long long left = 0;
	long long right = 2000000000LL * 1000000LL; // left, right는 '분'의 범위
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long begin, end;
		begin = 0, end = m;
		for (int i = 0; i < m; i++) { // mid분까지 놀이기구를 탄 학생의 수
			end += mid / a[i];
		}
		begin = end;
		for (int i = 0; i < m; i++) {
			if (mid % a[i] == 0) { // mid분에 놀이기구를 탄 학생의 수
				begin--;
			}
		}
		begin++;

		if (n < begin) {
			right = mid - 1;
		}
		else if (n > end) {
			left = mid + 1;
		}
		else { // n이 놀이기구를 탄 시간대를 찾음
			for (int i = 0; i < m; i++) {
				if (mid % a[i] == 0) { // n이 탄 놀이기구를 찾음
					if (n == begin) {
						printf("%d", i + 1);
						return 0;
					}
					begin++;
				}
			}
		}
	}
	return 0;
}