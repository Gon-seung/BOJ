#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long n = 0;
	cin >> n;
	vector<long long> answer(10, 0);
	long long size = 10;
	for (size = 10; size <= n; size *= 10) {
		answer[0] += (n / size - 1) * (size / 10);
		if (n % size - n % (size / 10) > 0) {
			answer[0] += size / 10;
		}
		else if (n % size - n % (size / 10) == 0) {
			answer[0] += n % (size / 10) + 1;
		}
	}

	for (size = 10; size <= n * 10; size *= 10) {
		for (int i = 1; i <= 9; i++) {
			answer[i] += (n / size) * (size / 10);
			if (n % size - n % (size / 10) > (size / 10) * i) {
				answer[i] += size / 10;
			}
			else if (n % size - n % (size / 10) == (size / 10) * i) {
				answer[i] += n % (size / 10) + 1;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}