//��� �����


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	//������ ��

	//------------------- �ʱⰪ ����
	//���� ũ�� �ޱ� , ��� ���� �ޱ�
	int N = 0;
	cin >> N;
	int num1 = 0;
	cin >> num1;
	//vector pair<int,int> : ������� ��ġ ���� data_apple
	vector<pair<int, int>> data_apple;
	int x = 0;
	int y = 0;
	for (int i = 0; i < num1; i++) {
		cin >> x;
		cin >> y;
		data_apple.push_back({ y,x });
	}

	//���� �� �ޱ�
	int num2 = 0;
	cin >> num2;
	//vector pair<int,char> : ������� ���� data_dir
	vector<pair<int, char>> data_dir;
	int x_d = 0;
	char d = '0';
	for (int i = 0; i < num2; i++) {
		cin >> x_d;
		cin >> d;
		data_dir.push_back({ x_d,d });
	}

	//vector pair<int,int>: �������� ���� tale
	vector<pair<int, int>> tale = { {1,1} };

	//time ����
	int time = 0;
	//���� ���� 0�� 1�� 2�� 3�Ʒ� : �ʱ� 2
	int dir = 2;

	//-------------------- �߰� ����
	while (true) {
		//1�� ���� �� �̵�
		// 1�� ���� �� �������� ���� �ϳ��� ���� tale[n-1] = n-2, n-2 = n-3 ,,,,,,
		//������ �� ����, �� ó�� ��ġ ���
		time += 1;
		pair<int, int> last_pos = tale[tale.size() - 1];
		for (int i = 0; i < tale.size() - 1; i++) {
			tale[tale.size() - 1 - i] = tale[tale.size() - 2 - i];
		}
		if (dir == 0) { tale[0].first -= 1; }
		else if (dir == 1) { tale[0].second -= 1; }
		else if (dir == 2) { tale[0].first += 1; }
		else if (dir == 3) { tale[0].second += 1; }

		//data_apple�� �� ó�� ��ġ�� ��� �Դ� ���� �˾Ƴ���
		//����� ���� ��� tale ���� �� �� �߰�
		//data_apple ���� iter �ּҰ� erase �� ������ �ٷ� break ó��
		//����� �� ���� ��� ����
		if (data_apple.size() > 0) {
			bool eat = false;
			for (auto i = data_apple.begin(); i != data_apple.end(); i++) {
				if (*i == tale[0]) { eat = true; data_apple.erase(i); break; }
			}
			if (eat) {
				tale.push_back(last_pos);
			}
		}


		//ó�� ��ġ�� ���� ��� �� < 1 or > N
		if (tale[0].first < 1 || tale[0].first > N || tale[0].second < 1 || tale[0].second > N) { break; }
		//���� �ε����� ��
		for (int i = 0; i < tale.size(); i++) {
			for (int j = i + 1; j < tale.size(); j++) {
				if (tale[i] == tale[j]) { goto end; }
			}
		}
		if (tale[0] == last_pos) { goto end; }

		//���� ��ȯ
		//ó�� �� �ð��� ������ ����
		//dir ���տ��� �� ó���� ����

		if (data_dir.size() > 0 && data_dir[0].first == time) {
			if (data_dir[0].second == 'D') { dir += 1; dir %= 4; }
			else { dir += 3; dir %= 4; }
			data_dir.erase(data_dir.begin());
		}
		//cout << time <<" " << tale.size()<< ":" << tale[0].first << " " << tale[0].second <<" " << dir <<  endl;
	}
end:
	cout << time;
	return 0;
}
