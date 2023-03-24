#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long answer = 0;
long long M = 0;
long long guessl = 1;
long long guessu = 0;

void Check_num(vector<int>& data) {
	long long guess = (guessl + guessu) / 2;
	int num = 0;
	for (int i = 0; i < data.size(); i++) {
		num += data[i] / guess;
	}
	if (num >= M) { answer = guess; guessl = guess + 1; }
	else { guessu = guess - 1; }

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> data;
	int N = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input = 0;
		cin >> input;
		if (input > guessu) { guessu = input; }
		data.push_back(input);
	}

	sort(data.begin(), data.end());

	while (guessl <= guessu) { Check_num(data); }
	cout << answer;
}

