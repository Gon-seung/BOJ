#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool Compare(string a, string b) {
	if (a.size() != b.size()) { return a.size() < b.size(); }
	else { return a < b; }

}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector<string> data(N);
	for (int i = 0; i < N; i++) {
		string x = "";
		cin >> x;
		data[i] = x;
	}
	sort(data.begin(), data.end(), Compare);
	string check = data[0];
	cout << data[0] << "\n";
	for (int i = 1; i < N; i++) {
		if (data[i] != check) {
			cout << data[i] << "\n";
			check = data[i];
		}
	}

	return 0;
}