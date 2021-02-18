#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> kmp(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int main() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string a;
	int ans = 0;
	for (char c : s) {
		a = c + a;
		vector<int> next = kmp(a);
		int m = next.size();
		for (int i = 0; i < m; i++) {
			if (ans < next[i]) ans = next[i];
		}
	}
	printf("%d", ans);
	return 0;
}