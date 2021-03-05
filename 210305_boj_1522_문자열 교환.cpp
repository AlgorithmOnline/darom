#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
string str;
int main() {
	cin >> str;
	int size = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'b') size++;
	}
	str += str;	
	int ans = size;
	queue<int> q;
	for (int i = 0; i < str.length(); i++) {
		if (!q.empty() && i - q.front() >= size) q.pop();
		if (str[i] == 'b') q.push(i);
		ans = min(ans, size - (int)q.size());
	}
	printf("%d", ans);
	return 0;
}