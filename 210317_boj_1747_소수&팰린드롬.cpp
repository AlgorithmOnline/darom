#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int n;
bool chk[1003002]; // 1000000보다 같거나 큰 소수중 가장 작은 소수는 1003001
int main() {
	scanf("%d", &n);
	vector<int> prime;
	for (int i = 2; i <= 1003001; i++) {
		if (chk[i]) continue;
		prime.push_back(i);
		for (int j = i + i; j <= 1003001; j += i) {
			chk[j] = true;
		}
	}

	for (auto e : prime) {
		if (e >= n) {
			string num = to_string(e);
			int len = num.length();
			bool flg = true;
			for (int i = 0; i < len / 2; i++) {
				if (num[i] != num[len - 1 - i]) {
					flg = false; break;
				}
			}
			if (flg) {
				printf("%d", e); break;
			}
		}
	}
	return 0;
}