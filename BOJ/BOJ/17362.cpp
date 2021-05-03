#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> answer;
	answer = { 2,1,2,3,4,5,4,3 };
	long long n;
	cin >> n;
	cout << answer[n % 8];
	return 0;
}

