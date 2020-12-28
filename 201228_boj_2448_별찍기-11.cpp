#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define BLANK ' '
#define STAR '*'
void solve(vector<vector<char>> &arr, int x, int y, int n, char color) {
	int i, j;
	if (color == BLANK) {
		int m = 2 * n - 1;
		for (i = x; i < x + n; i++) {
			for (j = 0; j < m; j++) {
				arr[i][j + i - x + y] = BLANK;
			}
			m -= 2;
		}
	}
	else if(color == STAR){
		if (n != 1) {
			int m = n / 2;
			solve(arr, x, y, m, STAR);
			solve(arr, x+m, y-m, m, STAR);
			solve(arr, x+m, y+m, m, STAR);
			if (n == 3) {
				solve(arr, x+1, y, 1, BLANK);
			}
			else {
				solve(arr, x+m, y-m+1, m, BLANK);
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<char>> arr(n, vector<char>(2 * n, STAR));
	solve(arr, 0, n - 1, n, STAR);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			arr[i][j] = BLANK;
			arr[i][2 * n - j - 2] = BLANK;
		}
		arr[i][2 * n - 1] = BLANK;
	}
	for (int i = 0; i < n; i++) {
		cout << string(arr[i].begin(), arr[i].end()) << '\n';
	}
	return 0;
}