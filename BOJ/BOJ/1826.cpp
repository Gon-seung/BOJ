#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Station {

public:
	int line;
	int gas;
};

bool Compare(Station a, Station b) {
	return a.line < b.line;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n = 0;
	cin >> n;
	vector<Station> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i].line;
		cin >> data[i].gas;
	}
	sort(data.begin(), data.end(), Compare);

	int dis = 0, remain = 0;
	cin >> dis >> remain;

	int answer = 0;
	int pos = 0;
	vector<int> sum_gas;
	while (remain < dis) {
		while (pos < n && data[pos].line <= remain) {
			sum_gas.push_back(data[pos].gas);
			pos += 1;
		}
		if (sum_gas.size() == 0) { break; }
		sort(sum_gas.begin(), sum_gas.end());
		remain += sum_gas.back();
		sum_gas.pop_back();
		answer += 1;
	}
	remain < dis ? cout << -1 : cout << answer;

	return 0;
}