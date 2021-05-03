#include<iostream>
#include <algorithm>
#include<vector>

using namespace std;

vector<vector<int>> Move(vector<vector<int>>& fish, int R, int C)
{
	vector<vector<int>> answer;
	vector<vector<int>> in(C);
	vector<vector<vector<int>>> data(R, in);
	//fish d 기준으로 이동한 값 구하기
	//0 r, 1 c, 2 s, 3 d, 4 z
	for (int i = 0; i < fish.size(); i++) {
		if (fish[i][3] == 1) { fish[i][0] -= fish[i][2]; }
		else if (fish[i][3] == 2) { fish[i][0] += fish[i][2]; }
		else if (fish[i][3] == 3) { fish[i][1] += fish[i][2]; }
		else if (fish[i][3] == 4) { fish[i][1] -= fish[i][2]; }

		if (fish[i][0] < 0) { fish[i][0] = -fish[i][0]; fish[i][3] = 3 - fish[i][3]; }
		if (fish[i][1] < 0) { fish[i][1] = -fish[i][1]; fish[i][3] = 7 - fish[i][3]; }
		fish[i][0] %= 2 * R - 2;
		fish[i][1] %= 2 * C - 2;
		if (fish[i][0] > R - 1) { fish[i][0] = 2 * R - 2 - fish[i][0]; fish[i][3] = 3 - fish[i][3]; }
		if (fish[i][1] > C - 1) { fish[i][1] = 2 * C - 2 - fish[i][1]; fish[i][3] = 7 - fish[i][3]; }

		if (data[fish[i][0]][fish[i][1]].empty()) { data[fish[i][0]][fish[i][1]] = fish[i]; }
		else if (data[fish[i][0]][fish[i][1]][4] < fish[i][4]) { data[fish[i][0]][fish[i][1]] = fish[i]; }
		//cout << fish[i][0] + 1 << ":" << fish[i][1] + 1 << ":" << fish[i][4] << "\n";
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!(data[i][j].empty())) { answer.push_back(data[i][j]); }
		}
	}
	return answer;
	//cout << "-----------------------" << endl;
	//만약 벽 통과시 그만큼 뒤집기
}

bool Compare(vector<int> a, vector<int> b) {
	if (a[0] != b[0]) { return a[0] < b[0]; }
	else if (a[1] != b[1]) { return a[1] < b[1]; }
	else { return a[4] < b[4]; }
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	//rcm
	//rc s d z
	int R = 0, C = 0, M = 0, r = 0, c = 0, s = 0, d = 0, z = 0;
	cin >> R >> C >> M;
	//상어 정보 입력받기
	vector<vector<int>> fish(M);
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		fish[i].push_back(r - 1);
		fish[i].push_back(c - 1);
		fish[i].push_back(s);
		fish[i].push_back(d);
		fish[i].push_back(z);
	}

	sort(fish.begin(), fish.end(), Compare);
	int total = 0;
	for (int j = 0; j < C; j++) {
		for (vector<vector<int>>::iterator i = fish.begin(); i != fish.end(); i++) {
			if ((*i)[1] == j) { total += (*i)[4]; fish.erase(i); break; }
		}
		//fish 이동 함수 제작
		fish = Move(fish, R, C);
		//fish 정렬


	}
	cout << total;
	return 0;
}
