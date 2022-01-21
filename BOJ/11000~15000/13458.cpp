//양식 저장용


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	//--------------- 초기값 설정
	//N 받기
	long long N;
	cin >> N;
	//Ai 받기
	vector<long long> ai;
	long long num = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		ai.push_back(num);
	}

	//B, C 받기
	long long B;
	long long C;
	cin >> B;
	cin >> C;

	//------------ 중간 계산과정
	//각 시험장 Ai의 감독관 수 계산
	//if(Ai - B > 0
	//(Ai - B) / C + 1
	long long answer = 0;
	for (int i = 0; i < ai.size(); i++) {
		if (ai[i] - B > 0) {
			if ((ai[i] - B) % C == 0) {
				answer += (ai[i] - B) / C + 1;
			}
			else {
				answer += (ai[i] - B) / C + 2;
			}
		}
		else { answer += 1; }
	}
	cout << answer;
	return 0;
}
