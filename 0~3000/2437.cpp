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
	vector<int> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data.begin(), data.end());
	int answer = 0;
	int pos = 1;
	int sum = data[0];
	while (pos < n&& sum >= data[pos] - 1) {
		sum += data[pos];
		pos += 1;
	}
	answer = sum + 1;
	data[0] > 1 ? cout << 1 : cout << answer;
	return 0;
}