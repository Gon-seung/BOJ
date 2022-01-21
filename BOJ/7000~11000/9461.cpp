#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<long long> data;
	data = { 1,1,1,2,2,3 };
	vector<int> output;
	int max = 0;
	for (int i = 0; i < n; i++) {
		int input = 0;
		cin >> input;
		output.push_back(input);
		if (max < input) { max = input; }
	}

	for (int i = 7; i <= max; i++) {
		data.push_back(data[data.size() - 1] + data[data.size() - 5]);
	}

	for (int i = 0; i < n; i++) {
		cout << data[output[i] - 1] << "\n";
	}
	return 0;
}