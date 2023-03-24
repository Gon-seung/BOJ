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
	int n;
	cin >> n;
	vector<int> input(n);
	int a;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		input[i] = a;
		if (max < a) { max = a; }
	}

	vector<int> prime = { 2 };
	for (int i = 3; i <= max; i++) {
		if (Check_prime(i, prime)) { prime.push_back(i); }
	}

	int answer = 0;
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < prime.size(); j++) {
			if (input[i] == prime[j]) { answer += 1; break; }
		}
	}
	cout << answer;
	return 0;
}
