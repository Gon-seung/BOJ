//양식 저장용

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	//N 입력받기
	int N = 0;
	cin >> N;
	//ti, pi 받기
	int ti = 0;
	int pi = 0;
	//vector<vector<int>> tp tp값들
	vector<vector<int>> tp(N);
	for (int i = 0; i < N; i++) {
		cin >> ti;
		cin >> pi;
		tp[i].push_back(ti);
		tp[i].push_back(pi);
	}

	//vector<int> date 일정있는 날짜는 1, 없으면 0
	vector<int> date(N);
	// i = 0~ 2 << 15까지
	int sum = 0;
	int max = 0;
	// 2<< 15
	for (int i = 0; i < 2 << 15; i++) {
		// j = 0 ~ N-1 까지
		sum = 0;
		for (int j = 0; j < N; j++) {
			date[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			// j번째 사람과 약속을 잡고 , 이전 사람과 약속이 안겹치면 맡고, 아니면 통과
			// (2 << j & i) == 1 && data[j]  == 0일 경우 date[j 부터 j + tp[j][1] - 1 까지] = 1로 변경 , 총합 변경
			//cout << (((2 << j) & i) >> j) << endl;
			if (((2 << j) & i) >> (j + 1) == 1 && date[j] == 0 && (j + tp[j][0]) <= N) {
				for (int k = 0; k < tp[j][0]; k++) { date[j + k] = 1; }
				sum += tp[j][1];
			}
			// else if (2 << j & i) == 1 일 경우 break
			else if (((2 << j) & i) >> (j + 1) == 1) { break; }
		}
		if (max < sum) { max = sum; }
	}

	cout << max;
	return 0;
}
