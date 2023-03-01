#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool went[100001];

vector<int> Check(vector<int> pos) {
	vector<int> answer;
	for (int i = 0; i < pos.size(); i++) {
		int newp = pos[i] - 1;
		if (newp >= 0 && newp <= 100000 && went[newp] == false) { went[newp] = true; answer.push_back(newp); }
		newp = pos[i] + 1;
		if (newp >= 0 && newp <= 100000 && went[newp] == false) { went[newp] = true; answer.push_back(newp); }
		newp = pos[i] * 2;
		if (newp >= 0 && newp <= 100000 && went[newp] == false) { went[newp] = true; answer.push_back(newp); }
	}
	return answer;

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> pos;
	pos = { n };
	int time = 0;
	went[n] = true;
	while (went[m] == false) {
		pos = Check(pos);
		time += 1;
	}

	cout << time;
	return 0;
}

