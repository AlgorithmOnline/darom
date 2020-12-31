#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
bool prime[10001]; // 4자리 정수 1000 ~ 9999
bool chk[10001];
int d[10001];
int change(int num, int index, int digit) {
	if (index == 0 && digit == 0) return -1;
	string s = to_string(num);
	s[index] = digit + '0'; // num to char
	return stoi(s);
}
int main() {
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		prime[i] = !prime[i];
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(chk, false, sizeof(chk));
		memset(d, 0, sizeof(d));
		d[n] = 0;
		chk[n] = true;
		queue<int> q;
		q.push(n);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(now, i, j);
					if (prime[next] && !chk[next]) {
						q.push(next);
						d[next] = d[now] + 1;
						chk[next] = true;
					}
				}
			}
		}
		printf("%d\n", d[m]);
	}
	return 0;
}