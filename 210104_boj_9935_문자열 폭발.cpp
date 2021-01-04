#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
char str[1000001];
bool erased[1000001];
char bomb[100];
int main() {
	scanf("%s", str);
	scanf("%s", bomb);
	int n = strlen(str);
	int m = strlen(bomb);
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			if (str[i] == bomb[0]) {
				erased[i] = true;
			}
		}
	}
	else {
		stack<pair<int, int>> s;
		for (int i = 0; i < n; i++) {
			if (str[i] == bomb[0]) {
				s.push({ i, 0 });
			}
			else {
				if (!s.empty()) {
					auto p = s.top();
					if (str[i] == bomb[p.second + 1]) {
						s.push({ i, p.second + 1 });
						if (p.second + 1 == m - 1) {
							for (int k = 0; k < m; k++) {
								auto p = s.top();
								s.pop();
								erased[p.first] = true; // 삭제								
							}
						}
					}
					else { // 현재위치까지 삭제할 수 있는 문자가 더 이상 없음
						while (!s.empty()) {
							s.pop();
						}
					}
				}
			}
		}
	}
	bool printed = false;
	for (int i = 0; i < n; i++) {
		if (erased[i]) continue;
		printf("%c", str[i]);
		printed = true;
	}
	if (!printed) {
		printf("FRULA\n");
	}
	return 0;
}