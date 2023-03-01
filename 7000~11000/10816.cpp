#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	map<int, int> data;
	int N = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input = 0;
		cin >> input;
		data[input] += 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int input = 0;
		cin >> input;
		cout << data[input] << " ";
	}

}

