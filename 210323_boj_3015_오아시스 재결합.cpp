#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int n;
long long int ans;
stack<pair<int, int>> st;
int main() {
	scanf("%d", &n);
	for (int i = 0, h; i < n; i++) {
		scanf("%d", &h);
		while (!st.empty() && st.top().first < h) {
			ans += st.top().second;
			st.pop();
		}

		if (st.empty()) st.push({ h, 1 });
		else {
			if (st.top().first > h) {
				ans += 1;
				st.push({ h, 1 });
			}
			else { // st.top().first == h
				auto top = st.top();
				ans += top.second;
				st.pop();
				if (st.size()) ans++; // 스택이 비지 않았다면 나보다 큰 한 명은 볼 수 있음
				top.second++;
				st.push(top);
			}
		}

	}
	printf("%lld", ans);
	return 0;
}