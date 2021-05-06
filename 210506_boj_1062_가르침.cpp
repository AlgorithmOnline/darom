#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int n, k, answer;
vector<string> s;
set<char> word;
bool chk[30];

void go(int idx, int cnt) {
	if (cnt == k) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			bool flg = true;
			for (auto e : s[i]) {
				if (!chk[e - 'a']) {
					flg = false; break;
				}
			}
			if (flg) {
				count++;
			}
		}
		answer = max(answer, count);
		return;
	}
	if (idx > 25) return;

	char c = 'a' + idx;
	if (!chk[idx] && word.find(c) != word.end()) {
		chk[idx] = true;
		go(idx + 1, cnt + 1);
		chk[idx] = false;
	}
	go(idx + 1, cnt);
}

int main() {
	scanf("%d%d", &n, &k);	
	s.resize(n);

	word.insert('a');
	word.insert('n');
	word.insert('t');
	word.insert('i');
	word.insert('c');

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		s[i] = s[i].substr(4, s[i].length() - 8);
		for (int j = 0; j < s[i].length(); j++) {
			word.insert(s[i][j]);
		}
	}

	if (word.size() <= k) answer = n;
	else if (k < 5) answer = 0;
	else {
		chk[0] = chk['n' - 'a'] = chk['t' - 'a'] = chk['i' - 'a'] = chk['c' - 'a'] = true;
		go(0, 5);
	}
	printf("%d", answer);
	return 0;
}