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
	int answer = 1;
	for (int i = 1; i <= N; i++) {
		answer *= i;
	}
	cout << answer;
	return 0;
}
