#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Rec(vector<int> data, int N, int M) {
	if (data.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << data[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			data.push_back(i + 1);
			Rec(data, N, M);
			data.pop_back();
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> print;
	print = {};
	vector<bool> check(N, false);
	Rec(print, N, M);

	return 0;
}