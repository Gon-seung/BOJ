//��� �����


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie();

	//------------------ �ʱⰪ ����
	// N M �Է�
	int N = 0;
	int M = 0;
	cin >> N;
	cin >> M;
	//pair<int,int> pos: map ���� �ֻ��� ��ġ
	int x = 0;
	int y = 0;
	cin >> x;
	cin >> y;
	pair<int, int> pos = { x,y };
	int k = 0;
	cin >> k;

	//vector<vector<int>> map : ���� map ��ġ ����, x,y �Է�
	vector<int> Q(M);
	vector<vector<int>> map(N, Q);
	int pos_xy = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pos_xy;
			map[i][j] = pos_xy;
		}
	}

	//vector<int> dice : �ֻ��� ��ġ ����, int�� �ֻ����� �ִ� ���� dice, �ʱⰪ�� ��� 0
	vector<int> dice = { 0,0,0,0,0,0 };
	//�̵��� ���� ǥ���� new_dice�� ����� �����
	vector<int> new_dice(dice);
	//pos�� ���� ��ġ : 0 �ٴ� 1 �� 2 �� 3 �� 4 �� 5 õ��

	//-------------------- ��� ����

	//���⿡ ���� �ֻ��� �� ����
	//dir ���� �� �ޱ�
	int dir = 0;
	for (int i = 0; i < k; i++) {
		cin >> dir;

		//pos �� �� ��� �� �ٱ����� �̵��Ǹ� �����ϸ� �ȵ�, �׸��� �����ؾ���.
		// �̻� ������ ���� �� ���
		pair<int, int> new_pos(pos);
		if (dir == 1) { new_pos.second += 1; }
		else if (dir == 2) { new_pos.second -= 1; }
		else if (dir == 3) { new_pos.first -= 1; }
		else if (dir == 4) { new_pos.first += 1; }

		if (new_pos.first < 0 || new_pos.second < 0 || new_pos.first >= N || new_pos.second >= M) {
			continue;
		}
		else { pos = new_pos; }
		// dir = 1
		// dice pos ��ġ ����� 0 -> 1, 1 -> 5, 5 -> 3, 3-> 0, 2,4 �״��
		// dir = 2
		// dice pos ��ġ ����� 0 -> 3, 3-> 5, 5->1 , 1-> 0 , 2 ,4 �״��
		//dir = 3
		// ���� 0 -> 4, 4-> 5, 5-> 2, 2-> 0, 1,3 �״��
		//dir = 4
		// ���� 0-> 2, 2-> 5, 5-> 4, 4-> 0, 1,3 �״��
		if (dir == 1) { new_dice[1] = dice[0]; new_dice[5] = dice[1]; new_dice[3] = dice[5]; new_dice[0] = dice[3]; }
		else if (dir == 2) { new_dice[3] = dice[0]; new_dice[5] = dice[3]; new_dice[1] = dice[5]; new_dice[0] = dice[1]; }
		else if (dir == 3) { new_dice[4] = dice[0]; new_dice[5] = dice[4]; new_dice[2] = dice[5]; new_dice[0] = dice[2]; }
		else if (dir == 4) { new_dice[2] = dice[0]; new_dice[5] = dice[2]; new_dice[4] = dice[5]; new_dice[0] = dice[4]; }
		dice = new_dice;
		//�̵� �� dice �ٴ� �� ����
		if (map[pos.first][pos.second] == 0) { map[pos.first][pos.second] = dice[0]; }
		else { dice[0] = map[pos.first][pos.second]; map[pos.first][pos.second] = 0; }
		//dice 5�� ���
		cout << dice[5] << endl;
	}
	return 0;
}
