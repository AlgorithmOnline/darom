#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int L, C;
vector<char> alpha;
bool check(string password) {
	int ja = 0, mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo += 1;
		}
		else {
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}
void go(string password, int i) {
	if (password.length() == L) {
		if (check(password)) {
			cout << password << '\n';
		}
		return;
	}
	if (i == alpha.size()) return;
	go(password + alpha[i], i + 1);
	go(password, i + 1);
}

int main() {	
	scanf("%d%d", &L, &C);
	alpha.resize(C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &alpha[i]);
	}
	sort(alpha.begin(), alpha.end());
	go("", 0);
	return 0;
}