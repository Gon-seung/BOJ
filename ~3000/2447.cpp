#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();
	int N;
	cin >> N;

	int count = 1;
	while (N != 3) {
		N /= 3;
		count += 1;
	}
	vector<vector<string>> star(7);
	star[0].push_back("***");
	star[0].push_back("* *");
	star[0].push_back("***");
	for (int i = 1; i < count; i++) {
		for (int j = 0; j < star[i - 1].size(); j++) {
			star[i].push_back(star[i - 1][j] + star[i - 1][j] + star[i - 1][j]);
		}

		string blank = "";
		for (int j = 0; j < star[i - 1].size(); j++) {
			blank += " ";
		}
		for (int j = 0; j < star[i - 1].size(); j++) {
			star[i].push_back(star[i - 1][j] + blank + star[i - 1][j]);
		}

		for (int j = 0; j < star[i - 1].size(); j++) {
			star[i].push_back(star[i - 1][j] + star[i - 1][j] + star[i - 1][j]);
		}
	}

	for (int i = 0; i < star[count - 1].size(); i++) {
		cout << star[count - 1][i] << endl;
	}

	return 0;
}
