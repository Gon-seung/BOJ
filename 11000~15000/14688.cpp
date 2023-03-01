#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

bool Check_num(int num, vector<int> oper, int N) {
	bool answer = true;
	vector<int> count(4, 0);
	for (int i = 0; i < N - 1; i++) {
		count[num % 4] += 1;
		num /= 4;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] != count[i]) { answer = false; }
	}

	return answer;
}

int main() {
	cin.tie();

	int N;
	cin >> N;
	vector<int> Ai(N);
	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		Ai[i] = num;
	}
	vector<int> oper(4);
	for (int i = 0; i < 4; i++) {
		cin >> num;
		oper[i] = num;
	}
	//4로 생각
	//0부터 1 << 4 * (N-1) 까지
	int check = 0;
	int min = 1 << 30;
	int max = -(1 << 30);
	int value = 0;
	for (int i = 0; i < 4 << (2 * (N - 2)); i++) {
		check = i;
		if (Check_num(i, oper, N)) {
			value = Ai[0];
			for (int j = 0; j < N - 1; j++) {
				if (check % 4 == 0) { value = value + Ai[j + 1]; }
				else if (check % 4 == 1) { value = value - Ai[j + 1]; }
				else if (check % 4 == 2) { value = value * Ai[j + 1]; }
				else if (check % 4 == 3) { value = value / Ai[j + 1]; }
				check /= 4;
			}
			if (max < value) { max = value; }
			if (min > value) { min = value; }

		}
	}
	cout << max << endl;
	cout << min << endl;
	//+-X/의 개수 구하기
	//while(count < N)
	//vector<int> number(4);


	return 0;
}
