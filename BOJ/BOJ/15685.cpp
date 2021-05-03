#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	//N �巡�� ����
	int N = 0;
	cin >> N;
	//x y d g
	int x, y, d, g = 0;
	vector<vector<int>> data;
	vector<bool> in(101, false);
	vector<vector<bool>> xy_pos(101, in);
	for (int i = 0; i < N; i++) {
		data.clear();
		cin >> x;
		cin >> y;
		cin >> d;
		cin >> g;
		//xy ��ǥ dir 0�� 1�� 2�� 3�� gen ����
		//vector<int> data�� ��� ���� ����
		data.push_back({ x, y });
		if (d == 0) { data.push_back({ x + 1,y }); }
		else if (d == 1) { data.push_back({ x,y - 1 }); }
		else if (d == 2) { data.push_back({ x - 1,y }); }
		else if (d == 3) { data.push_back({ x,y + 1 }); }
		//gen ������ data�� �������� ȸ���� ������ �־����.

		for (int j = 0; j < g; j++) {
			int size = data.size();
			int rot_x = data[size - 1][0];
			int rot_y = data[size - 1][1];
			for (int k = 1; k < size; k++) {
				//cout << data[size - 1 - k][1] - rot_y + rot_x << ":" << -data[size - 1 - k][0] + rot_x + rot_y << endl;
				data.push_back({ -data[size - 1 - k][1] + rot_y + rot_x, data[size - 1 - k][0] - rot_x + rot_y });
			}
		}
		for (int j = 0; j < data.size(); j++) {
			//cout << data[j][0] << data[j][1] << endl;
			xy_pos[data[j][0]][data[j][1]] = true;
		}
		//�ð�������� ȸ���� a,b�� �߽����� xy�� �����϶� : x,y-> y - b + a, -x + a + b
	}
	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (xy_pos[i][j] == 1 && xy_pos[i + 1][j] == 1 && xy_pos[i][j + 1] == 1 && xy_pos[i + 1][j + 1] == 1) {
				count += 1;
				//cout << i << ":" << j << endl;
			}
		}
	}
	cout << count;

	return 0;
}
