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
	vector<int> answer = { 0,1 };
	for (int i = 2; i <= N; i++) {
		answer.push_back(answer[i - 1] + answer[i - 2]);
	}
	cout << answer[N];
	return 0;
}
