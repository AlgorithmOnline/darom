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
	int n;
	string s;
	cin >> n >> s;
	auto next = kmp(s);
	printf("%d", n - next[n - 1]);
	return 0;
}