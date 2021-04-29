#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int k;
	cin >> n >> k;
	long long ming = 1;
	long long maxg = n * n;
	long long answer = 0;
	while (maxg >= ming) {
		long long guess = (ming + maxg) / 2;
		long long count = 0;
		for (int i = 0; i < n; i++) {
			count += min(n, guess / (i + 1));
		}
		//cout << guess << count << endl;
		if (count < k) { ming = guess + 1; }
		else { answer = guess; maxg = guess - 1; }
	}
	cout << answer;
	return 0;
}

