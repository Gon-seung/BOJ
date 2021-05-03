#include <iostream>
#include <vector>

using namespace std;


bool Check_prime(int num, vector<int> prime) {
	bool answer = true;

	for (int i = 0; i < prime.size(); i++) {
		if (num % prime[i] == 0) { answer = false; break; }
	}

	return answer;
}
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	//n ¹Þ±â
	int m, n = 0;
	cin >> m;
	cin >> n;

	vector<int> prime = { 2 };
	for (int i = 3; i <= n; i++) {
		if (Check_prime(i, prime)) { prime.push_back(i); }
	}

	int answer = 0;
	int min = -1;
	for (int i = m; i <= n; i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (i == prime[j]) {
				answer += i;
				if (min == -1) { min = i; }
				break;

			}
		}
	}
	if (answer != 0) {
		cout << answer << endl << min;
	}
	else { cout << min; }
	return 0;
}
