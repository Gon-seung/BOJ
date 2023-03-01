//양식 저장용


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie();

	//------------------ 초기값 설정
	// N M 입력
	int N = 0;
	int M = 0;
	cin >> N;
	cin >> M;
	//pair<int,int> pos: map 상의 주사위 위치
	int x = 0;
	int y = 0;
	cin >> x;
	cin >> y;
	pair<int, int> pos = { x,y };
	int k = 0;
	cin >> k;

	//vector<vector<int>> map : 지도 map 위치 설정, x,y 입력
	vector<int> Q(M);
	vector<vector<int>> map(N, Q);
	int pos_xy = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pos_xy;
			map[i][j] = pos_xy;
		}
	}

	//vector<int> dice : 주사위 위치 설정, int는 주사위에 있는 값들 dice, 초기값은 모두 0
	vector<int> dice = { 0,0,0,0,0,0 };
	//이동후 값을 표시할 new_dice도 겸사겸사 만들기
	vector<int> new_dice(dice);
	//pos에 따른 위치 : 0 바닥 1 서 2 북 3 동 4 남 5 천장

	//-------------------- 계산 과정

	//방향에 따른 주사위 값 설정
	//dir 방향 값 받기
	int dir = 0;
	for (int i = 0; i < k; i++) {
		cin >> dir;

		//pos 값 선 계산 후 바깥으로 이동되면 저장하면 안됨, 그리고 무시해야함.
		// 이상 없으면 저장 후 계산
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
		// dice pos 위치 변경들 0 -> 1, 1 -> 5, 5 -> 3, 3-> 0, 2,4 그대로
		// dir = 2
		// dice pos 위치 변경들 0 -> 3, 3-> 5, 5->1 , 1-> 0 , 2 ,4 그대로
		//dir = 3
		// 변경 0 -> 4, 4-> 5, 5-> 2, 2-> 0, 1,3 그대로
		//dir = 4
		// 변경 0-> 2, 2-> 5, 5-> 4, 4-> 0, 1,3 그대로
		if (dir == 1) { new_dice[1] = dice[0]; new_dice[5] = dice[1]; new_dice[3] = dice[5]; new_dice[0] = dice[3]; }
		else if (dir == 2) { new_dice[3] = dice[0]; new_dice[5] = dice[3]; new_dice[1] = dice[5]; new_dice[0] = dice[1]; }
		else if (dir == 3) { new_dice[4] = dice[0]; new_dice[5] = dice[4]; new_dice[2] = dice[5]; new_dice[0] = dice[2]; }
		else if (dir == 4) { new_dice[2] = dice[0]; new_dice[5] = dice[2]; new_dice[4] = dice[5]; new_dice[0] = dice[4]; }
		dice = new_dice;
		//이동 후 dice 바닥 값 변경
		if (map[pos.first][pos.second] == 0) { map[pos.first][pos.second] = dice[0]; }
		else { dice[0] = map[pos.first][pos.second]; map[pos.first][pos.second] = 0; }
		//dice 5값 출력
		cout << dice[5] << endl;
	}
	return 0;
}
