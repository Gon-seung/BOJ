#include <iostream>
#include <vector>
using namespace std;

vector<int> Do(vector<bool> done, vector<int> fri, vector<vector<int>> data) {
	vector<int> answer;
	answer = {};
	for (int i = 0; i < fri.size(); i++) {
		for (int j = 0; j < data.size(); j++) {
			if (!done[j] && data[fri[i]][j]) {
				answer.push_back(j);
				//cout << fri[i] << " " << j << endl;
			}
		}
	}

	return answer;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<int>> data(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		data[x - 1][y - 1] = 1;
		data[y - 1][x - 1] = 1;
	}
	vector<int> fri;
	fri = { 0 };
	vector<bool> done(n, false);

	for (int i = 0; i < fri.size(); i++)
	{
		done[fri[i]] = true;
	}
	fri = Do(done, fri, data);
	for (int i = 0; i < fri.size(); i++)
	{
		done[fri[i]] = true;
	}
	fri = Do(done, fri, data);
	for (int i = 0; i < fri.size(); i++)
	{
		done[fri[i]] = true;
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (done[i]) { count += 1; }
	}
	cout << count - 1;
	return 0;
}

