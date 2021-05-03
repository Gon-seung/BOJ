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

	//입력 N, M 받기
	int N;
	int M;
	cin >> N;
	cin >> M;

	//숫자 받기
	int num;
	vector<vector<int>> floor(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			floor[i].push_back(num);
		}
	}

	//vector<int> data(4) : 블록 안의 숫자들
	vector<int> data(4);
	//일자형
	//가로 0 ~ N - 4
	int max = 0;
	int sum = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i <= M - 4; i++) {
			sum = 0;
			sum += floor[j][i];
			sum += floor[j][i + 1];
			sum += floor[j][i + 2];
			sum += floor[j][i + 3];
			if (sum > max) { max = sum; }
		}
	}
	//세로 0 ~ M - 4
	for (int i = 0; i < M; i++) {
		for (int j = 0; j <= N - 4; j++) {
			sum = 0;
			sum += floor[j + 1][i];
			sum += floor[j + 2][i];
			sum += floor[j + 3][i];
			sum += floor[j][i];
			if (sum > max) { max = sum; }
		}
	}

	//나머지 2 X 2 정사각형 위치 설정, 뺄 곳 k 설정(0,2,4,6), 넣을 곳 h 설정(0,1,2,3,4,5,6,7,8)
	//뺄곳하고 넣을 곳 /2가 같으면 coninue
	//다르면 값 구하고, max < 이면 max 재설정
	int x = 0;
	int y = 0;
	int x_del = 0;
	int y_del = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			sum = 0;
			sum += floor[i][j];
			sum += floor[i][j + 1];
			sum += floor[i + 1][j];
			sum += floor[i + 1][j + 1];
			for (int k = 0; k <= 6; k += 2) {
				for (int h = 0; h <= 8; h++) {
					if (k / 2 == h / 2) { continue; }
					else if (k == 0) { x = i; y = j; }
					else if (k == 2) { x = i; y = j + 1; }
					else if (k == 4) { x = i + 1; y = j + 1; }
					else if (k == 6) { x = i + 1; y = j; }
					x_del = x; y_del = y;
					if (h == 0) { x = i; y = j - 1; }
					else if (h == 1) { x = i - 1; y = j; }
					else if (h == 2) { x = i - 1; y = j + 1; }
					else if (h == 3) { x = i; y = j + 2; }
					else if (h == 4) { x = i + 1; y = j + 2; }
					else if (h == 5) { x = i + 2; y = j + 1; }
					else if (h == 6) { x = i + 2; y = j; }
					else if (h == 7) { x = i + 1; y = j - 1; }
					else if (h == 8) { x = x_del; y = y_del; }

					if (x < 0 || x > N - 1 || y < 0 || y > M - 1) { continue; }
					else { sum -= floor[x_del][y_del]; sum += floor[x][y]; }

					if (sum > max) {
						max = sum;
					}
					sum += floor[x_del][y_del]; sum -= floor[x][y];
				}
			}
		}
	}

	cout << max;
	return 0;
}
