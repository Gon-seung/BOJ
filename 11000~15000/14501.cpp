//��� �����

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	//N �Է¹ޱ�
	int N = 0;
	cin >> N;
	//ti, pi �ޱ�
	int ti = 0;
	int pi = 0;
	//vector<vector<int>> tp tp����
	vector<vector<int>> tp(N);
	for (int i = 0; i < N; i++) {
		cin >> ti;
		cin >> pi;
		tp[i].push_back(ti);
		tp[i].push_back(pi);
	}

	//vector<int> date �����ִ� ��¥�� 1, ������ 0
	vector<int> date(N);
	// i = 0~ 2 << 15����
	int sum = 0;
	int max = 0;
	// 2<< 15
	for (int i = 0; i < 2 << 15; i++) {
		// j = 0 ~ N-1 ����
		sum = 0;
		for (int j = 0; j < N; j++) {
			date[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			// j��° ����� ����� ��� , ���� ����� ����� �Ȱ�ġ�� �ð�, �ƴϸ� ���
			// (2 << j & i) == 1 && data[j]  == 0�� ��� date[j ���� j + tp[j][1] - 1 ����] = 1�� ���� , ���� ����
			//cout << (((2 << j) & i) >> j) << endl;
			if (((2 << j) & i) >> (j + 1) == 1 && date[j] == 0 && (j + tp[j][0]) <= N) {
				for (int k = 0; k < tp[j][0]; k++) { date[j + k] = 1; }
				sum += tp[j][1];
			}
			// else if (2 << j & i) == 1 �� ��� break
			else if (((2 << j) & i) >> (j + 1) == 1) { break; }
		}
		if (max < sum) { max = sum; }
	}

	cout << max;
	return 0;
}
