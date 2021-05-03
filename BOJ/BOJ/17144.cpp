#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Move(vector<vector<int>> data, int x, int y) {
	int R = data.size();
	int C = data[0].size();
	vector<int> in(C);
	vector<vector<int>> answer(R, in);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (data[i][j] <= 0) { continue; }
			else {
				int plus = data[i][j] / 5;
				int count = 0;
				if (i > 0 && data[i - 1][j] != -1) { answer[i - 1][j] += plus; count += 1; }
				if (j > 0 && data[i][j - 1] != -1) { answer[i][j - 1] += plus; count += 1; }
				if (i < R - 1 && data[i + 1][j] != -1) { answer[i + 1][j] += plus; count += 1; }
				if (j < C - 1 && data[i][j + 1] != -1) { answer[i][j + 1] += plus; count += 1; }
				answer[i][j] += data[i][j] - plus * count;
			}
		}
	}

	answer[x][y] = -1;
	answer[x - 1][y] = -1;
	return answer;
}

void Move_air(vector<vector<int>>& data, int x, int y) {
	int R = data.size();
	int C = data[0].size();

	// 1��
	for (int i = x - 2; i > 0; i--) {
		data[i][0] = data[i - 1][0];
	}
	for (int i = x + 1; i < R - 1; i++) {
		data[i][0] = data[i + 1][0];
	}
	// 1�� R��
	for (int i = 0; i < C - 1; i++) {
		data[0][i] = data[0][i + 1];
		data[R - 1][i] = data[R - 1][i + 1];
	}
	// C��
	for (int i = 0; i < x - 1; i++) {
		data[i][C - 1] = data[i + 1][C - 1];
	}
	for (int i = R - 1; i > x; i--) {
		data[i][C - 1] = data[i - 1][C - 1];
	}

	// x, x-1��
	for (int i = C - 1; i > 1; i--) {
		data[x][i] = data[x][i - 1];
		data[x - 1][i] = data[x - 1][i - 1];
	}

	data[x][1] = 0;
	data[x - 1][1] = 0;

}

int main() {

	int R = 0, C = 0, T = 0;
	cin >> R >> C >> T;

	int input = 0;
	vector<vector<int>> data(R);
	int air_x = 0, air_y = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> input;
			data[i].push_back(input);
			if (input == -1) { air_x = i; air_y = j; }
		}
	}
	//�̼����� Ȯ��
	//û���⳪ ���̸� ����
	//���� ai / 5
	//���� �� = ai -ai / 5 * ����
	for (int i = 0; i < T; i++) {
		data = Move(data, air_x, air_y);

		Move_air(data, air_x, air_y);
		/*cout << i << "end---------------------" << endl;
		for (int k = 0; k < R; k++) {
			for (int j = 0; j < C; j++) {
				cout << data[k][j] << " ";
			}
			cout << "\n";
		}*/
	}

	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (data[i][j] != -1) { answer += data[i][j]; }
		}
	}

	cout << answer;
	//����û���� �̵�
	//����û���� ���� y + 1�� �̵�
	//1�� ����û���� �� x + 1 �� �̵� pos -1����
	//1�� ����û���� �Ʒ� x-1�� �̵� pos +2����
	//n-1�� ����û���� ��
	return 0;
}