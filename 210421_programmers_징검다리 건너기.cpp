#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int left = 0, right = *max_element(stones.begin(), stones.end());

	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 0; i < stones.size(); i++) {
			if (stones[i] - mid < 0) {
				cnt++;
				if (cnt >= k) {
					cnt = k + 1; break;
				}
			}
			else cnt = 0;
		}

		if (cnt <= k) {
			left = mid + 1;
			answer = max(answer, mid);
		}
		else right = mid - 1;
	}
	
	return answer;
}