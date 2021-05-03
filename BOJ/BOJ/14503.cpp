#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

bool Watch(vector<vector<int>> data, int r, int c, int dir) {
	bool answer = false;
	if (dir == 0) {
		if (data[r][c - 1] == 0) { c -= 1; answer = true; }
	}
	else if (dir == 1) {
		if (data[r - 1][c] == 0) { r -= 1; answer = true; }

	}
	else if (dir == 2) {
		if (data[r][c + 1] == 0) { c += 1; answer = true; }

	}
	else if (dir == 3) {
		if (data[r + 1][c] == 0) { r += 1; answer = true; }

	}
	return answer;
}

vector<int> Toward(int r, int c, int d) {
	if (d == 0) { r -= 1; }
	else if (d == 1) { c += 1; }
	else if (d == 2) { r += 1; }
	else if (d == 3) { c -= 1; }
	return { r,c };
}

int main() {
	cin.tie();
	// N,M받기
	int N = 0;
	int M = 0;
	cin >> N;
	cin >> M;
	//r,c,d 받기
	//0 북 1 동 2 남 3 서 
	//rc는 행 렬 
	int r = 0;
	int c = 0;
	int d = 0;
	cin >> r;
	cin >> c;
	cin >> d;

	int statue = 0;
	vector<int> in(M);
	vector<vector<int>> data(N, in);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> statue;
			data[i][j] = statue;
		}
	}
	//1. 자리 청소
	//2-1 왼쪽에 청소 안한 곳이 있을 경우, 왼쪽 회전 후 한칸 전진 -> 1로 이동
	//2-2 else 왼쪽 회전후 2-1로 이동
	//4방향 모두 청소가 되어있으면 후진후 2-1로 이동
	//후진도 못하면 정지
	bool end = true;
	int count = 0;
	while (end) {
		vector<int> pos;
		data[r][c] = 2;
		//cout << r << " "<< c << endl;
		if (Watch(data, r, c, d)) { count = 0;  d = (d + 3) % 4; pos = Toward(r, c, d); r = pos[0]; c = pos[1]; }
		else if (!Watch(data, r, c, d) && count < 4) { count += 1; d = (d + 3) % 4; }
		else {
			count = 0;
			while (true) {
				bool check = true;
				for (int i = 0; i < 4; i++) {
					check = check & !Watch(data, r, c, i);
				}
				pos = Toward(r, c, (d + 2) % 4);
				bool block = false;
				if (data[pos[0]][pos[1]] == 1) { block = true; }
				if (check && !block) { r = pos[0]; c = pos[1]; break; }
				else { end = false; break; }
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (data[i][j] == 2) { answer += 1; }
			//cout << data[i][j] << " ";
		}
		//cout << endl;
	}
	cout << answer << endl;
	return 0;
}
