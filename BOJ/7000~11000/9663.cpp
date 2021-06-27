#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Recur(vector<pair<int, int>>& pos, vector<bool>& sum, vector<bool>& sub, vector<bool>& line) {
	int answer = 0;
	if (pos.size() == line.size()) {
		answer += 1;
	}
	else {
		for (int i = 0; i < line.size(); i++) {
			//cout << line[0] << line[1] << line[2] << line[3] << endl;
			//cout << !sum[pos.size() + i] << !line[i] << !sub[pos.size() - i + line.size() - 1] << endl;

			if (!sum[pos.size() + i] && !line[i] && !sub[pos.size() - i + line.size() - 1])
			{
				sum[pos.size() + i] = true;
				line[i] = true;
				sub[pos.size() - i + line.size() - 1] = true;
				pos.push_back({ pos.size() , i });
				answer += Recur(pos, sum, sub, line);
				//cout << pos.size() << " " << answer << endl;
				pos.pop_back();
				sum[pos.size() + i] = false;
				line[i] = false;
				sub[pos.size() - i + line.size() - 1] = false;
			}
		}
	}
	return answer;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N = 0;
	cin >> N;

	vector<pair<int, int>> pos;
	vector<bool> sum(2 * N - 1, false);
	vector<bool> sub(2 * N - 1, false);
	vector<bool> line(N, false);
	int answer = Recur(pos, sum, sub, line);
	cout << answer;
	return 0;
}