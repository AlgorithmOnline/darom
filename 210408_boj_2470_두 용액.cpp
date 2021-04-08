#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
int n, ans;
int main() {
	scanf("%d", &n);
	vector<int> liquid(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &liquid[i]);
	}
	sort(liquid.begin(), liquid.end());
	int left = 0, right = liquid.size() - 1;
	int Min = 1e9 * 2 + 1, m_left = 0, m_right = 0;
	while (left < right) {
		ll sum = liquid[left] + liquid[right];
		if (abs(sum) < Min) {
			Min = abs(sum); 
			m_left = liquid[left], m_right = liquid[right];
			if(Min == 0) break;
		}
		if (sum > 0) {
			right--;
		}
		else left++;
	}
	printf("%d %d", m_left, m_right);
	return 0;
}