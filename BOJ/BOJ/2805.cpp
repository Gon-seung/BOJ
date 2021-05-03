#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long answer = 0;
long long M = 0;
long long guessl = 1;
long long guessu = 0;

void Check_num(vector<int> data, vector<long long> sum) {
	long long guess = (guessl + guessu) / 2;
	auto pos = lower_bound(data.begin(), data.end(), guess);
	int len = data.end() - pos;
	if (M <= sum[sum.size() - 1] - sum[sum.size() - 1 - len] - guess * len) { answer = guess; guessl = guess + 1; }
	else { guessu = guess - 1; }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> data;
	vector<long long> sum;
	long long N = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input = 0;
		cin >> input;
		data.push_back(input);
	}

	sort(data.begin(), data.end());
	sum.push_back(0);
	for (int i = 0; i < N; i++) {
		sum.push_back(sum[i] + data[i]);

	}
	guessu = data[N - 1];
	while (guessl <= guessu) { Check_num(data, sum); }
	cout << answer;
}

