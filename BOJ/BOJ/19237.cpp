#include <iostream>
#include <vector>

using namespace std;

//Move �Լ�
vector<int >Move(vector<int>& fish, vector<vector<pair<int, int>>>& data, vector<vector<vector<int>>>& dir, int time) {
	vector<int> answer = fish;
	for (int i = 0; i < 8; i++) {
		//cout << fish[0] - 1 << ":" << fish[3] - 1 << endl;
		//cout << dir[fish[0] - 1][fish[3] - 1][i] << endl;
		int want_dir = dir[fish[0] - 1][fish[3] - 1][i % 4];
		int dir_x = 0;
		int dir_y = 0;
		if (want_dir == 1) { dir_x = -1; }
		else if (want_dir == 2) { dir_x = 1; }
		else if (want_dir == 3) { dir_y = -1; }
		else if (want_dir == 4) { dir_y = 1; }

		int x = fish[1] + dir_x; int y = fish[2] + dir_y;
		if (i < 4) {
			if (x >= 0 && y >= 0 && x < data.size() && y < data.size() && data[x][y].second <= time - 1) {
				//cout << data[x][y].second << "SAdfsdfadfsadf:" << time << endl;
				return { fish[0],x,y,want_dir };

			}
			else { continue; }
		}
		else if (x >= 0 && y >= 0 && x < data.size() && y < data.size() && data[x][y].first == fish[0] && data[x][y].second > time - 1) {
			return{ fish[0],x,y,want_dir };
		}
	}
	return answer;
	//1�� 2�Ʒ� 3 ���� 4 ������

	//answer�� 0��° : ���ũ�� , 1��° : x��, 2��° y��, 3��° ������ ��������.
}

int main() {

	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;

	vector<vector<int>> pos(M);// ������ ��ġ���� ���� (0��° : ���ũ��, 1��° : x��, 2��° y��, 3��° ����)

	int input = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input != 0) { pos[input - 1] = { input,i,j,0 }; }
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> input;
		pos[i][3] = input;
	}

	vector<vector<pair<int, int>>> data(N, vector<pair<int, int>>(N, { 0, -K - 1 })); // ������ ����� ����
	//ù��°�� ��. �ι�°�� ����� ���� ��
	for (int i = 0; i < pos.size(); i++) {
		data[pos[i][1]][pos[i][2]] = { pos[i][0],0 };
	}
	vector<vector<vector<int>>> dir(M, vector<vector<int>>(4, vector<int>(4, 0))); // ����� �켱���� ���� ����
	//i��° ��� //j+1������ //  k�켱������
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> input;
				dir[i][j][k] = input;
			}
		}
	}

	//1�� 2�Ʒ� 3 ���� 4 ������
	//Move �Լ� -> ����� ������ �� ���� / input���� ����� pos, data, dir
	int time = 0;
	while (time < 1001) {
		time += 1;
		vector<vector<bool>> duplicate(N, vector<bool>(N, true)); // �� ���ڿ� ���� �� �ִ��� ������ Ȯ��
		vector<vector<int>> new_pos;



		for (int i = 0; i < pos.size(); i++) {
			vector<int> check_pos(4);
			check_pos = Move(pos[i], data, dir, time - K);
			//cout << check_pos[0] << ":" << check_pos[1] << " :" << check_pos[2] << ":" << check_pos[3] << ":" << pos.size()<< endl;
			if (duplicate[check_pos[1]][check_pos[2]]) {
				duplicate[check_pos[1]][check_pos[2]] = false;
				new_pos.push_back(check_pos);
			}
			else { continue; }
		}
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (data[i][j].second != 0) {
					data[i][j].second -= 1;
					if (data[i][j].second == 0) { data[i][j] = { 0,0 }; }
				}
			}
		}*/
		for (int i = 0; i < new_pos.size(); i++) {
			//cout << new_pos[i][0] << ":" << new_pos[i][1] + 1 << ":" << new_pos[i][2] + 1 << endl;
			data[new_pos[i][1]][new_pos[i][2]] = { new_pos[i][0],time };
		}
		if (new_pos.size() == 1) { break; }
		pos = new_pos;
	}
	if (time > 1000) { time = -1; }
	cout << time;
	return 0;
}
