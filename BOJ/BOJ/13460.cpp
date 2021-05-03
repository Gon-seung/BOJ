//양식 저장용


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> Move_Dir(vector<char> data, int r, int b, int x, int dir) {
	pair<int, int> answer = { 0,0 };
	//dir 0오 1왼 2아래 3위
	int k = 0;
	if (dir == 0) { k = 1; }
	else if (dir == 1) { k = -1; }
	else if (dir == 2) { k = x; }
	else if (dir == 3) { k = -x; }

	if ((r > b && (dir == 0 || dir == 2)) || (r < b && (dir == 1 || dir == 3))) {
		while (true) {
			//cout << r << ":" << b << ":" << k << endl;
			if (data[r + k] == 'O') { answer.first = r + k; r = r + k;  break; }
			if (data[r + k] == '#' || r + k == b) { answer.first = r; break; }
			r = r + k;
		}
		while (true) {
			//cout << r << ":" << b << ":" << k << endl;

			if (data[b + k] == 'O') { answer.second = b + k; b = b + k; break; }
			if (data[b + k] == '#' || b + k == r) { answer.second = b; break; }
			b = b + k;
		}
	}
	else {
		while (true) {
			if (data[b + k] == 'O') { answer.second = b + k; b = b + k; break; }
			if (data[b + k] == '#' || b + k == r) { answer.second = b; break; }
			b = b + k;
		}
		while (true) {
			if (data[r + k] == 'O') { answer.first = r + k; r = r + k; break; }
			if (data[r + k] == '#' || r + k == b) { answer.first = r; break; }
			r = r + k;
		}
	}
	return answer;

}


int main() {
	//유지 해야 할 값들 R 위치, B 위치, 횟수, 위치 값들

	int x = 0;
	int y = 0;
	cin >> x;
	cin >> y;


	string back;
	vector<char> data;
	int r_pos = 0;
	int b_pos = 0;
	int o_pos = 0;
	pair<int, int> rb_pos;
	for (int i = 0; i < x; i++) {
		cin >> back;
		for (int j = 0; j < y; j++) {
			data.push_back(back[j]);
			if (back[j] == 'R') { r_pos = i * y + j; }
			else if (back[j] == 'B') { b_pos = i * y + j; }
			else if (back[j] == 'O') { o_pos = i * y + j; }
		}
	}
	vector<pair<int, int>> data_pos;
	data_pos.push_back({ r_pos, b_pos });
	//Move_Dir 함수 : input - data, R위치, B위치,가로, 방향  /output - R 위치, B위치
	int count = 0;
	int check_bef_bef = 0;
	while (true) {


		int check_bef = data_pos.size();
		count += 1;
		for (int k = check_bef_bef; k < check_bef; k++) {
			r_pos = data_pos[k].first;
			b_pos = data_pos[k].second;
			for (int i = 0; i < 4; i++) {
				rb_pos = Move_Dir(data, r_pos, b_pos, y, i);
				//if (rb_pos.second == 34) { cout << i << " " << r_pos << " " << b_pos << endl; }
				//cout << rb_pos.first << " " << rb_pos.second << endl;
				bool check = true;
				if (rb_pos.second == o_pos) { check = false; }
				if (rb_pos.first == o_pos && rb_pos.second != o_pos) { goto end; }
				for (int j = 0; j < data_pos.size(); j++) {
					if (data_pos[j] == rb_pos) { check = false; break; }
				}
				if (check) { data_pos.push_back(rb_pos); }
			}
		}
		check_bef_bef = check_bef;
		if (check_bef == data_pos.size()) { count = -1; break; }
	}
end:
	if (count > 10) { count = -1; }
	cout << count;
	//위 함수 output이 R만 출구면 통과, B만 출구면 없애고, 위치 값들에 포함되면 없애고, R,B 둘다 출구여도 없애고
	//위 함수 후에도 위치 값들 set이 변하지 않으면 -1리턴



	return 0;
}
