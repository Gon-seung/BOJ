#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

vector<int> Rotate(vector<int> whirl, int dir) {
	vector<int> answer(8);
	if (dir == 0) { answer = whirl; }
	else if (dir == 1) {
		for (int i = 0; i < 7; i++) {
			answer[i + 1] = whirl[i];
		}
		answer[0] = whirl[7];
	}
	else {
		for (int i = 0; i < 7; i++) {
			answer[i] = whirl[i + 1];
		}
		answer[7] = whirl[0];
	}
	return answer;
}

int main() {
	cin.tie();

	vector<int> in(8);
	vector<vector<int>> wh(4, in);
	string input = "";
	for (int j = 0; j < 4; j++) {
		cin >> input;
		for (int i = 0; i < 8; i++) {
			wh[j][i] = stoi(input.substr(i, 1));
		}
	}

	int K = 0;
	int num = 0;
	int dir = 0;

	//극이 다르면 다른 방향으로 회전
	//극이 같으면 이동 x
	//2번과 6번이 다른 톱니바퀴랑 닿음.
	//
	cin >> K;
	vector<int> dir_wh(4);
	for (int i = 0; i < K; i++) {
		cin >> num;
		cin >> dir;
		int count = 0;
		dir_wh[num - 1] = dir;
		while (num + count <= 3) {
			if (wh[num - 1 + count][2] != wh[num + count][6]) { dir_wh[num + count] = -dir_wh[num - 1 + count]; }
			else { dir_wh[num + count] = 0; }
			count += 1;
		}
		count = 0;
		while (num + count - 2 >= 0) {
			if (wh[num - 1 + count][6] != wh[num - 2 + count][2]) { dir_wh[num + count - 2] = -dir_wh[num - 1 + count]; }
			else { dir_wh[num + count - 2] = 0; }
			count -= 1;
		}
		for (int i = 0; i < 4; i++) {
			wh[i] = Rotate(wh[i], dir_wh[i]);
		}
		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cout << wh[i][j];
			}
			cout << endl;
		}*/
	}
	cout << wh[0][0] + wh[1][0] * 2 + wh[2][0] * 4 + wh[3][0] * 8 << endl;
	return 0;
}
