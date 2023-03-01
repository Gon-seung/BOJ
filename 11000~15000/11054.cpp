#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		data[i] = input;
	}

	//위치와 배열의 길이를 pair로 가지는 vector
	map<int, int> up;
	map<int, int> down;

	//up[i] i 번째의 가장 큰 배열수
	for (int i = 0; i < n; i++) {
		up[i] = 1;
		down[i] = 1;
		for (int j = 0; j < i; j++) {
			if (data[j] < data[i] && up[i] < up[j] + 1) { up[i] = up[j] + 1; }
			if (data[j] > data[i] && down[i] < up[j] + 1) { down[i] = up[j] + 1; }
			if (data[j] > data[i] && down[i] < down[j] + 1) { down[i] = down[j] + 1; }
		}

	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		//cout << up[i] << " " << down[i] << endl;
		if (up[i] > max) { max = up[i]; }
		if (down[i] > max) { max = down[i]; }
	}
	cout << max << endl;
	return 0;
}