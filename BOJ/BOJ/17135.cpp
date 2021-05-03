#include <iostream>
#include <vector>
using namespace std;

int n, m, d;

int Start(vector<vector<int>> data, vector<int> pos) {
	int answer = 0;

	//m,i

	for (int k = 0; k < n; k++) {
		vector<vector<int>> del_pos;
		for (int j = 0; j < 3; j++) {
			int count = 1;
			int i = pos[j];
			vector<vector<int>> shoot;
			vector<vector<int>> new_shoot;
			new_shoot = { {n - 1,i} };
			while (count <= d) {
				//cout << d << endl;
				count += 1;
				shoot = new_shoot;
				new_shoot.clear();
				int size = shoot.size();
				bool del = false;
				for (int w = 0; w < size; w++) {
					if (data[shoot[w][0]][shoot[w][1]] == 1) {
						del_pos.push_back({ shoot[w][0],shoot[w][1] });
						del = true;
						break;
					}
				}
				if (del) { break; }
				if (size > 0) {
					if (shoot[0][1] - 1 >= 0) { new_shoot.push_back({ shoot[0][0], shoot[0][1] - 1 }); }
					for (int w = 0; w < size; w++) {
						if (shoot[w][0] - 1 >= 0) { new_shoot.push_back({ shoot[w][0] - 1,shoot[w][1] }); }
					}
					if (shoot[size - 1][1] + 1 < m) { new_shoot.push_back({ shoot[size - 1][0], shoot[size - 1][1] + 1 }); }
				}

			}

		}
		for (int i = 0; i < del_pos.size(); i++) {
			int x = del_pos[i][0];
			int y = del_pos[i][1];
			if (data[x][y] != 0) { data[x][y] = 0; answer += 1; }
		}
		for (int i = n - 1; i > 0; i--) {
			data[i] = data[i - 1];
		}
		for (int i = 0; i < m; i++) {
			data[0][i] = 0;
		}
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> d;
	vector<vector<int>> data(n, vector<int>(m, 0));
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> data[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				max = Start(data, { i,j,k }) > max ? Start(data, { i,j,k }) : max;
			}
		}
	}
	cout << max;
	return 0;
}

