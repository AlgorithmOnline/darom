#include <string>
#include <vector>
using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	vector<int> start, end;

	for (auto line : lines) {
		string h, m, s, ms;
		int ih, im, is, process;

		line.pop_back(); // s제외
		h = line.substr(11, 2);
		m = line.substr(14, 2);
		s = line.substr(17, 2);
		ms = line.substr(20, 3);
		// 처리량을 ms로 표현
		process = stof(line.substr(24)) * 1000;
		ih = stoi(h) * 3600 * 1000;
		im = stoi(m) * 60 * 1000;
		is = stoi(s) * 1000 + stoi(ms);

		start.push_back(ih + im + is - process + 1);
		end.push_back(ih + im + is);
	}

	for (int i = 0; i < lines.size(); i++) {
		int end_time = end[i] + 1000; // 1초간 처리량 구하기
		int cnt = 0;
		for (int j = i; j < lines.size(); j++) {
			if (start[j] < end_time) cnt++;
			//else break; -> 하면 틀림 정렬한게 아니기 때문에
		}
		if (answer < cnt) answer = cnt;
	}

	return answer;
}

int main() {
	vector<string> lines = { "2016-09-15 20:59:57.421 0.351s",
							"2016-09-15 20:59:58.233 1.181s",
							"2016-09-15 20:59:58.299 0.8s",
							"2016-09-15 20:59:58.688 1.041s",
							"2016-09-15 20:59:59.591 1.412s",
							"2016-09-15 21:00:00.464 1.466s",
							"2016-09-15 21:00:00.741 1.581s",
							"2016-09-15 21:00:00.748 2.31s",
							"2016-09-15 21:00:00.966 0.381s",
							"2016-09-15 21:00:02.066 2.62s" 
	};
	printf("%d", solution(lines));
	return 0;
}