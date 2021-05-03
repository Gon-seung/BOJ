#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, x = 0;
	cin >> n >> x;
	vector<int> data(n + 1);
	int input;
	long long answer = 0;
	cin >> answer;
	answer *= x;
	cin >> input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		answer += input;
		answer %= 1000000007;
		if (i == n - 1) { break; }
		answer *= x;
		cin >> input;
		//cout << answer << endl;
	}
	cout << answer;
	return 0;
}