#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string input = "";
	cin >> input;

	int pos = 0;
	int size = 1;
	int answer = 0;
	bool check = false;
	while (pos + size < input.size()) {
		if (input[pos + size] == '-') {
			answer += stoi(input.substr(pos, size));
			pos = pos + size + 1;
			size = 1;
			check = true;
			break;
		}
		else if (input[pos + size] == '+') {
			answer += stoi(input.substr(pos, size));
			pos = pos + size + 1;
			size = 1;
		}
		else { size += 1; }
	}
	while (pos + size < input.size()) {
		if (input[pos + size] == '-' || input[pos + size] == '+') {
			answer -= stoi(input.substr(pos, size));
			pos = pos + size + 1;
			size = 1;
		}
		else { size += 1; }
	}
	int extra = stoi(input.substr(pos, size));
	check ? answer -= extra : answer += extra;

	cout << answer;

	return 0;
}

