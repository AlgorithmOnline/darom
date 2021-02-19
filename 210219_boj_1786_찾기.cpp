#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> preprocessing(string p) {
	int m = p.size();
	int j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string s, string p)
{
	vector<int> ans;
	auto pi = preprocessing(p);
	int n = s.size(), m = p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main() {
	string s, p;
	getline(cin, s);
	getline(cin, p);

	vector<int> matched = kmp(s, p);
	printf("%d\n", (int)matched.size());

	for (auto i : matched) {
		printf("%d ", i + 1);
	}

	return 0;
}