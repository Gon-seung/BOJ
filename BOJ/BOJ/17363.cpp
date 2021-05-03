#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	map<char, char> answer;
	int n = 0, m = 0;
	cin >> n >> m;
	answer['.'] = '.';
	answer['O'] = 'O';
	answer['-'] = '|';
	answer['|'] = '-';
	answer['/'] = 92;
	answer[92] = '/';
	answer['^'] = '<';
	answer['<'] = 118;
	answer[118] = '>';
	answer['>'] = '^';
	vector<vector<char>> output(m, vector<char>(n, 0));
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			output[m - 1 - j][i] = answer[a[j]];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << output[i][j];
		}
		cout << "\n";
	}
	return 0;
}

