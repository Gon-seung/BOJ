#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	vector<int> prime;
	vector<bool> check_prime(n + 1, false);
	check_prime[0] = true;
	check_prime[1] = true;
	for (int i = 1; i <= n; i++) {
		if (check_prime[i]) { continue; }
		int pos = i * 2;
		while (pos <= n) { check_prime[pos] = true; pos += i; }
	}
	for (int i = 0; i <= n; i++) {
		if (!check_prime[i]) { prime.push_back(i); }
	}
	int prime_pos = 0;
	while (n != 1) {
		if (n % prime[prime_pos] == 0) {
			cout << prime[prime_pos] << "\n";
			n /= prime[prime_pos];
		}
		else { prime_pos += 1; }
	}
	return 0;
}