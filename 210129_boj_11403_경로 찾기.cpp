#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, d[101][101];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j]) {
					d[i][j] = 1;					
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}