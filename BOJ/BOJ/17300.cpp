#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;



int main() {

	int len = 0;
	int a = 0;

	set<int> check;
	cin >> len;
	vector<int> data;
	vector<int> turnon = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < len; i++) {
		cin >> a;
		data.push_back(a);
	}

	bool check_no = false;
	for (int i = 1; i < data.size(); i++) {
		check.insert(data[i]);
		check.insert(data[i - 1]);
		if (check.size() == 1) { check_no = true; cout << "NO"; break; }
		int x = *check.begin();
		int y = *++check.begin();

		if (x == 1 && y == 3 && turnon[2] == 0) { check_no = true; cout << "NO"; }
		else if (x == 7 && y == 9 && turnon[8] == 0) { check_no = true; cout << "NO"; }
		else if (x == 1 && y == 7 && turnon[4] == 0) { check_no = true; cout << "NO"; }
		else if (x == 3 && y == 9 && turnon[6] == 0) { check_no = true; cout << "NO"; }
		else if (x == 1 && y == 9 && turnon[5] == 0) { check_no = true; cout << "NO"; }
		else if (x == 3 && y == 7 && turnon[5] == 0) { check_no = true; cout << "NO"; }
		else if (x == 4 && y == 6 && turnon[5] == 0) { check_no = true; cout << "NO"; }
		else if (x == 2 && y == 8 && turnon[5] == 0) { check_no = true; cout << "NO"; }
		else if (turnon[x] == 1 || turnon[y] == 1) { check_no = true; cout << "NO"; }
		turnon[data[i - 1]] = 1;
		if (check_no) { break; }
		check.clear();
	}
	if (!check_no) { cout << "YES"; }

	return 0;

}