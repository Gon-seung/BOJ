#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector<int> data(N);
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		data[i] = input;

	}
	sort(data.begin(), data.end());
	int sum = data[0];
	int count = 1;
	int max_count = 1;
	vector<int> great = { data[0] };
	for (int i = 0; i < N - 1; i++) {
		if (data[i + 1] == data[i]) {
			count += 1;
		}
		else {
			if (i == 0) { great.clear(); }
			if (count == max_count) { great.push_back(data[i]); }
			else if (count > max_count) { max_count = count; great.clear(); great.push_back(data[i]); }
			count = 1;
		}
		sum += data[i + 1];
	}
	if (count == max_count) { great.push_back(data[data.size() - 1]); }
	else if (count > max_count) { max_count = count; great.clear(); great.push_back(data[data.size() - 1]); }


	if ((sum % N) * 2 > N) { cout << sum / N + 1 << endl; }
	else if ((sum % N) * 2 < -N) { cout << sum / N - 1 << endl; }
	else { cout << sum / N << endl; }
	cout << data[(N - 1) / 2] << endl;
	if (great.size() > 1) { cout << great[1] << endl; }
	else { cout << great[0] << endl; }
	cout << data[data.size() - 1] - data[0] << endl;

	return 0;
}