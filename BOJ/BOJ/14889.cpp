#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	//N값 받기
	int N;
	cin >> N;

	vector<int> in(N);
	vector<vector<int>> data(N, in);
	int input = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			data[i][j] = input;
		}
	}

	//i는 1부터 1<<20까지
	int num0 = 0;
	int num1 = 0;
	int sum = 1 << 30;
	for (int i = 0; i < 1 << N; i++) {
		num0 = 0;
		num1 = 0;
		for (int j = 0; j < N; j++) {
			if (((1 << j) & i) != 0) { num1 += 1; }
			else { num0 += 1; }
		}
		if (num0 != num1) { continue; }

		int sum_check = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (((1 << j) & i) != 0 && ((1 << k) & i) != 0) { sum_check += data[j][k] + data[k][j]; }
				if (((1 << j) & i) == 0 && ((1 << k) & i) == 0) { sum_check -= data[j][k] + data[k][j]; }
			}
		}

		if (sum_check < 0) { sum_check = -sum_check; }
		if (sum_check / 2 < sum) { sum = sum_check / 2; }
	}
	cout << sum << endl;
	//i의 0과 1의 개수가 같은지 확인

	//총합 차이 확인
	//02 05 20 25 50 52 (1 1 2 3 5 5) 13 14 31 34 41 43 (2 2 3 4 4 4)
	return 0;
}
