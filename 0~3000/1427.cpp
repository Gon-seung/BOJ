#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string N = "";
	cin >> N;

	vector<int> data(N.size());
	for (int i = 0; i < N.size(); i++) {
		data[i] = stoi(N.substr(i, 1));
	}
	sort(data.begin(), data.end());
	for (int i = 0; i < N.size(); i++) {
		cout << data[N.size() - 1 - i];
	}

	return 0;
}