//양식 저장용

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int Check_0num(vector<int> data) {
	int answer = 0;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == 0) { answer += 1; }
	}
	return answer;
}

vector<int> Virus(vector<int> floor, int N, int M) {
	vector<int> answer;
	vector<int> pivot;
	answer = floor;
	while (true) {
		pivot = answer;
		for (int i = 0; i < answer.size(); i++) {
			if (answer[i] == 2) {
				if (i % M != 0 && answer[i - 1] != 1) { answer[i - 1] = 2; }
				if (i % M != M - 1 && answer[i + 1] != 1) { answer[i + 1] = 2; }
				if (i / M != 0 && answer[i - M] != 1) { answer[i - M] = 2; }
				if (i / M != N - 1 && answer[i + M] != 1) { answer[i + M] = 2; }
			}
		}
		if (pivot == answer) {
			break;
		}
	}
	//cout << Check_0num(answer) << endl;
	return answer;
}


int main() {
	cin.tie();

	//N,M 받기
	int N = 0;
	int M = 0;
	cin >> N;
	cin >> M;
	//vector<int> floor
	vector<int> floor;
	//NM 순으로 num 받기
	int num = 0;
	for (int i = 0; i < N * M; i++) {
		cin >> num;
		floor.push_back(num);
	}

	//pos 3개를 -1로 정의하고 시작
	int posx = -1;
	int posy = -1;
	int posz = -1;
	bool check = true;
	int max = 0;
	vector<int> new_floor(floor);
	//for 3개 문으로
	// 0 ~ N*M // i + 1 ~ N*M // j + 1 ~ N*M
	//check 설정후 못했으면 없애기
	for (int i = 0; i < N * M - 2; i++) {

		posx = -1;
		posy = -1;
		posz = -1;
		check = true;
		if (floor[i] == 0) { posx = i; }
		else { continue; }
		for (int j = i + 1; j < N * M - 1; j++) {
			if (floor[j] == 0) { posy = j; }
			else { continue; }
			for (int k = j + 1; k < N * M; k++) {
				if (floor[k] == 0) {
					posz = k;
					new_floor = floor;
					new_floor[posx] = 1;
					new_floor[posy] = 1;
					new_floor[posz] = 1;
					new_floor = Virus(new_floor, N, M);
					if (max < Check_0num(new_floor)) {
						max = Check_0num(new_floor);
					}
					//if (posx == 4 && posy == 9 && posz == 21) {
					//	cout << posx << " " << posy << " " << posz << " " << Check_0num(new_floor) << endl;
					//}
				}
				else { continue; }
			}


		}
	}

	//바이러스 퍼지는 거 시작 floor 받고 리턴하면 될듯
	cout << max;
	return 0;
}
