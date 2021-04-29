#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	int count = 0;
	int num = 666;
	while (true) {
		int check = num;
		while (check > 0) {
			if (check % 1000 == 666) { count += 1; break; }
			else { check /= 10; }
		}
		if (count == N) { cout << num; break; }
		num += 1;
	}

	return 0;
}