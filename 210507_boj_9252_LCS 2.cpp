#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string str1, str2;
int lcs[1001][1001];

int main() {
	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;

	// LCS 알고리즘을 위해 앞에 '0'을 붙여준다.
	str1 = '0' + tmp1;
	str2 = '0' + tmp2;

	int len1 = str1.size(), len2 = str2.size();

	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (i == 0 || j == 0) {
				lcs[i][j] = 0;
				continue;
			}

			// 현재 비교하는 값이 서로 같다면, lcs는 + 1
			if (str1[i] == str2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			// 서로 다르다면 LCS의 값을 왼쪽 혹은 위에서 가져온다.
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j] = lcs[i][j - 1]);
		}
	}
	printf("%d\n", lcs[len1 - 1][len2 - 1]);

	int i = len1 - 1, j = len2 - 1;
	vector<int> v;
	while (lcs[i][j] != 0) {
		if (lcs[i][j] == lcs[i][j - 1]) j--;
		else if (lcs[i][j] == lcs[i - 1][j]) i--;
		else if (lcs[i][j] - 1 == lcs[i - 1][j - 1]) 	{
			v.push_back(i);
			i--; j--;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%c", str1[v[i]]);
	}
	return 0;
}