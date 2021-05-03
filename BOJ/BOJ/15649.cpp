#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Rec(vector<int> data, vector<bool> check, int N, int M) {
	if (data.size() == M) {
		for (int i = 0; i < M; i++) {
			cout << data[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!check[i]) {
				data.push_back(i + 1);
				check[i] = true;
				Rec(data, check, N, M);
				data.pop_back();
				check[i] = false;
			}
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
	Rec(print, check, N, M);


	return 0;
}