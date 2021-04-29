#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long n = 0, m = 0;
	long long check = 5;
	long long answer5 = 0;
	cin >> n >> m;
	while (check <= n) {
		answer5 += n / check;
		answer5 -= m / check;
		answer5 -= (n - m) / check;
		check *= 5;
	}
	check = 2;
	long long answer2 = 0;
	while (check <= n) {
		answer2 += n / check;
		answer2 -= m / check;
		answer2 -= (n - m) / check;
		check *= 2;
	}
	cout << (answer2 < answer5 ? answer2 : answer5);
	return 0;
}

