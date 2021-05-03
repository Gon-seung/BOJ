#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {

	string input;
	int k;

	cin >> input;
	cin >> k;

	bool check = false;
	for (int i = 0; i <= input.size() / 2; i++) {
		if (input[i] != input[input.size() - 1 - i] && !check) { check = true;  cout << "NO"; }
	}
	if (!check) { cout << "YES"; }
	return 0;


}