#include <iostream>
#include <vector>
using namespace std;

bool Check(int x, int y, int size, vector<vector<char>>& data) {
	int color = data[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (data[i][j] != color) { return false; }
		}
	}
	return true;
}

string Start(pair<int, int> pos, int size, vector<vector<char>>& data) {
	string answer = "";
	int x = pos.first;
	int y = pos.second;
	if (Check(x, y, size, data)) {
		answer += data[x][y];
	}
	else {
		answer += "(";
		answer += Start({ x,y }, size / 2, data);
		answer += Start({ x,y + size / 2 }, size / 2, data);
		answer += Start({ x + size / 2,y }, size / 2, data);
		answer += Start({ x + size / 2,y + size / 2 }, size / 2, data);
		answer += ")";
	}

	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	string answer = "";
	vector<vector<char>> data(n, vector<char>(n, 0));
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			data[i][j] = input[j];
		}
	}
	answer = Start({ 0,0 }, n, data);
	cout << answer << "\n";
	return 0;
}

