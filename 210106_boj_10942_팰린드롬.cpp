#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[2001];
int dp[2001][2001];
int n, m;
int go(int i, int j) {
	int& ret = dp[i][j];
	if (i == j) {
		ret = 1;
		return ret;
	}
	if (i + 1 == j) {
		if (arr[i] == arr[j]) {
			ret = 1; return ret;
		}
		else {
			ret = 0; return 0;
		}
	}
	if (ret > 0)return ret;
	if (arr[i] != arr[j]) {
		ret = 0; return ret;
	}
	else return ret = go(i + 1, j - 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &m);
	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", go(s, e));
	}

	return 0;
}