#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const long long mod = 100000;
string s;
long long d[200][200];
char open[5] = "({[";
char close[5] = ")}]";
long long go(int i, int j) {
	if (i > j) {
		return 1;
	}
	long long& ans = d[i][j];
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	for (int k = i + 1; k <= j; k += 2) { // 괄호 문자열의 짝 확인(2칸씩 이동)
		for (int l = 0; l < 3; l++) { // 어떤 괄호가 오는지 구현
			if (s[i] == open[l] || s[i] == '?') {
				if (s[k] == close[l] || s[k] == '?') {
					long long tmp = go(i + 1, k - 1) * go(k + 1, j);
					ans += tmp;
					if (ans >= mod) {
						ans = ans % mod + mod; // 출력 때 판별위해서 mod를 더해줌
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	cin >> s;
	memset(d, -1, sizeof(d));
	long long ans = go(0, n - 1);
	if (ans >= mod) {
		printf("%05lld\n", ans % mod);
	}
	else {
		printf("%lld\n", ans);
	}
	return 0;
}