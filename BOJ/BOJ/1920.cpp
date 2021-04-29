#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> data;
	int N = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input = 0;
		cin >> input;
		data.push_back(input);
	}
	cin >> M;
	sort(data.begin(), data.end());
	for (int i = 0; i < M; i++) {
		int input = 0;
		cin >> input;
		cout << binary_search(data.begin(), data.end(), input) << "\n";
	}

}

