//양식 저장용


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	//죽으면 끝

	//------------------- 초기값 설정
	//보드 크기 받기 , 사과 개수 받기
	int N = 0;
	cin >> N;
	int num1 = 0;
	cin >> num1;
	//vector pair<int,int> : 사과들의 위치 집합 data_apple
	vector<pair<int, int>> data_apple;
	int x = 0;
	int y = 0;
	for (int i = 0; i < num1; i++) {
		cin >> x;
		cin >> y;
		data_apple.push_back({ y,x });
	}

	//방향 수 받기
	int num2 = 0;
	cin >> num2;
	//vector pair<int,char> : 방향들의 집합 data_dir
	vector<pair<int, char>> data_dir;
	int x_d = 0;
	char d = '0';
	for (int i = 0; i < num2; i++) {
		cin >> x_d;
		cin >> d;
		data_dir.push_back({ x_d,d });
	}

	//vector pair<int,int>: 꼬리들의 집합 tale
	vector<pair<int, int>> tale = { {1,1} };

	//time 설정
	int time = 0;
	//방향 설정 0왼 1위 2오 3아래 : 초기 2
	int dir = 2;

	//-------------------- 중간 진행
	while (true) {
		//1초 증가 후 이동
		// 1초 증가 시 꼬리들의 집합 하나씩 댕기기 tale[n-1] = n-2, n-2 = n-3 ,,,,,,
		//마지막 값 저장, 맨 처음 위치 계산
		time += 1;
		pair<int, int> last_pos = tale[tale.size() - 1];
		for (int i = 0; i < tale.size() - 1; i++) {
			tale[tale.size() - 1 - i] = tale[tale.size() - 2 - i];
		}
		if (dir == 0) { tale[0].first -= 1; }
		else if (dir == 1) { tale[0].second -= 1; }
		else if (dir == 2) { tale[0].first += 1; }
		else if (dir == 3) { tale[0].second += 1; }

		//data_apple과 맨 처음 위치로 사과 먹는 유무 알아내기
		//사과를 먹을 경우 tale 집합 맨 뒤 추가
		//data_apple 제거 iter 주소값 erase 한 다음에 바로 break 처리
		//사과를 안 먹은 경우 냅둠
		if (data_apple.size() > 0) {
			bool eat = false;
			for (auto i = data_apple.begin(); i != data_apple.end(); i++) {
				if (*i == tale[0]) { eat = true; data_apple.erase(i); break; }
			}
			if (eat) {
				tale.push_back(last_pos);
			}
		}


		//처음 위치가 벽일 경우 끝 < 1 or > N
		if (tale[0].first < 1 || tale[0].first > N || tale[0].second < 1 || tale[0].second > N) { break; }
		//뱀이 부딪히면 끝
		for (int i = 0; i < tale.size(); i++) {
			for (int j = i + 1; j < tale.size(); j++) {
				if (tale[i] == tale[j]) { goto end; }
			}
		}
		if (tale[0] == last_pos) { goto end; }

		//방향 전환
		//처음 값 시간이 같으면 진행
		//dir 집합에서 맨 처음은 제거

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
