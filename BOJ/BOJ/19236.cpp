#include <iostream>
#include <vector>

using namespace std;

vector < vector < pair<int, int>>> Move(vector < vector < pair<int, int>>> input) {
	vector < vector < pair<int, int>>> data = input;
	for (int i = 1; i <= 16; i++) {
		int pos = -1;
		for (int j = 0; j < 16; j++) {
			if (data[j / 4][j % 4].first == i) { pos = j; break; }
		}
		if (pos == -1) { continue; }
		int dir = data[pos / 4][pos % 4].second;
		int count = 0;
		while (count < 8) {
			pair<int, int> temp = { 0,0 };
			int dir_x = 0; int dir_y = 0;
			int x = pos / 4; int y = pos % 4;
			if (dir == 1) { dir_x = -1; }
			else if (dir == 2) { dir_x = -1; dir_y = -1; }
			else if (dir == 3) { dir_y = -1; }
			else if (dir == 4) { dir_x = 1; dir_y = -1; }
			else if (dir == 5) { dir_x = 1; }
			else if (dir == 6) { dir_x = 1; dir_y = 1; }
			else if (dir == 7) { dir_y = 1; }
			else if (dir == 8) { dir_x = -1; dir_y = 1; }

			if (x + dir_x >= 0 && x + dir_x < 4 && y + dir_y >= 0 && y + dir_y < 4 && data[x + dir_x][y + dir_y].first != 17) {

				//cout << data[x + dir_x][y + dir_y].first << ":" <<  data[x][y].first << endl;
				temp = data[x + dir_x][y + dir_y];
				data[x + dir_x][y + dir_y] = { data[x][y].first , dir };
				data[x][y] = temp;
				break;
			}
			else { dir = (dir % 8 + 1); count += 1; }
		}
	}

	return data;
}

vector<pair<int, vector<vector<pair<int, int>>>>> Start(pair<int, vector<vector<pair<int, int>>>> input, int& sum)
{
	vector<pair<int, vector<vector<pair<int, int>>>>> answer;
	vector<vector<pair<int, int>>> data = Move(input.second);

	int pos = 0;
	for (int j = 0; j < 16; j++) {
		if (data[j / 4][j % 4].first == 17) { pos = j; break; }
	}

	int dir = data[pos / 4][pos % 4].second;

	int x = pos / 4; int y = pos % 4;
	int dir_x = 0; int dir_y = 0;
	if (dir == 1) { dir_x = -1; }
	else if (dir == 2) { dir_x = -1; dir_y = -1; }
	else if (dir == 3) { dir_y = -1; }
	else if (dir == 4) { dir_x = 1; dir_y = -1; }
	else if (dir == 5) { dir_x = 1; }
	else if (dir == 6) { dir_x = 1; dir_y = 1; }
	else if (dir == 7) { dir_y = 1; }
	else if (dir == 8) { dir_x = -1; dir_y = 1; }

	int count = 1;
	vector<vector<pair<int, int>>> new_data;

	while (x + dir_x * count >= 0 && x + dir_x * count < 4 && y + dir_y * count >= 0 && y + dir_y * count < 4) {
		if (data[x + dir_x * count][y + dir_y * count].first == 0) { count += 1; continue; }
		new_data = data;
		new_data[x + dir_x * count][y + dir_y * count] = { 17 , data[x + dir_x * count][y + dir_y * count].second };
		new_data[x][y] = { 0,0 };
		answer.push_back({ input.first + data[x + dir_x * count][y + dir_y * count].first, new_data });
		/*cout << input.first + data[x + dir_x * count][y + dir_y * count].first
		<< ":" << data[x + dir_x * count][y + dir_y * count].second << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << new_data[i][j].first << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		count += 1;
	}
	if (answer.empty() && input.first > sum) {
		sum = input.first;

	}

	return answer;

}
int main() {

	//vector<vector<pair<int,int>>> fish 값들 저장
	vector<vector<pair<int, int>>> fish(4, vector<pair<int, int>>(4, { 0,0 }));
	int x = 0, y = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x >> y;
			fish[i][j].first = x;
			fish[i][j].second = y;
		}
	}
	//Move fish -> 이동한 값 정의
	//sum -> 상어가 먹은 양
	//data에 fish 지도랑 sum을 페어로 둔다
	//각각의 data에 대해서 끝날 경우 sum값이 가장 큰 값을 정답으로 처리
	int sum = fish[0][0].first;
	fish[0][0].first = 17;
	vector<pair<int, vector<vector<pair<int, int>>>>> data;
	data.push_back({ sum, fish });
	while (data.size() > 0) {
		vector<pair<int, vector<vector<pair<int, int>>>>> new_data;
		vector<pair<int, vector<vector<pair<int, int>>>>> temp;
		for (int i = 0; i < data.size(); i++) {
			temp = Start(data[i], sum);
			//			cout << sum << endl;
			for (int j = 0; j < temp.size(); j++) {
				new_data.push_back(temp[j]);
				//cout << "sum" << sum << endl;

			}
		}
		data = new_data;

	}
	cout << sum << endl;

	return 0;
}