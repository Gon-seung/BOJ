#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<int> sortdice(6);
	for (int i = 0; i < 6; i++) {
		cin >> sortdice[i];
	}
	vector<int> dice = sortdice;
	sort(dice.begin(), dice.end());
	int first = dice[0];
	int second = 1 << 29;
	int third = 1 << 29;
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (i + j != 5) {
				sum = sortdice[i] + sortdice[j];
				if (sum < second) { second = sum; }
			}
			for (int k = j + 1; k < 6; k++) {
				if ((i + j != 5) && (j + k != 5) && (i + k != 5)) {
					sum = sortdice[i] + sortdice[j] + sortdice[k];
					if (sum < third) { third = sum; }
				}
			}
		}
	}
	if (n > 1) {
		cout << first * ((long long)n * n * 5 - 16 * n + 12) + second * (8 * n - 12) + third * 4;
	}
	else { cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4]; }
	return 0;
}