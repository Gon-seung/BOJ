#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leftt = 0;

bool Check_in(int x, int y, int n, int m) {
	if (x >= 0 && x < n && y >= 0 && y < m) { return true; }
	else { return false; }
}

vector<pair<int, int>> Check(vector<vector<int>>& data, vector<pair<int, int>> pos) {
	int n = data.size();
	int m = data[0].size();
	vector<pair<int, int>> answer;

	for (int i = 0; i < pos.size(); i++) {
		int x = pos[i].first;
		int y = pos[i].second;
		vector<pair<int, int>> xy_pos = { {x + 1,y},{x - 1,y},{x,y + 1},{x,y - 1} };
		for (int j = 0; j < xy_pos.size(); j++) {
			if (Check_in(xy_pos[j].first, xy_pos[j].second, n, m) && data[xy_pos[j].first][xy_pos[j].second] == 0) {
				data[xy_pos[j].first][xy_pos[j].second] = 1;
				leftt -= 1;
				answer.push_back({ xy_pos[j].first,xy_pos[j].second });
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
	cin >> m >> n;
	vector<vector<int>> data(n, vector<int>(m, 0));
	vector<pair<int, int>> pos;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> data[i][j];
			if (data[i][j] == 1) { pos.push_back({ i,j }); }
			if (data[i][j] == 0) { leftt += 1; }
		}
	}
	int day = 0;
	while (pos.size() && leftt != 0) {
		pos = Check(data, pos);
		day += 1;
		//cout << leftt << endl;
	}
	if (leftt > 0) { day = -1; }
	cout << day;
	return 0;
}

