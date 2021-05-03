#include <iostream>
#include <vector>

using namespace std;

void Move(vector<vector<int>>& data, vector<vector<int>>& fri_data, int L, int R, int i, int j) {
	int count = fri_data[i][j];
	int n = data.size();
	int com = 0;
	if (i > 0 && fri_data[i - 1][j] == 0) {
		com = abs(data[i][j] - data[i - 1][j]);
		if (com >= L && com <= R) { fri_data[i - 1][j] = count; Move(data, fri_data, L, R, i - 1, j); }
	}
	if (j > 0 && fri_data[i][j - 1] == 0) {
		com = abs(data[i][j] - data[i][j - 1]);
		if (com >= L && com <= R) { fri_data[i][j - 1] = count; Move(data, fri_data, L, R, i, j - 1); }
	}
	if (i < n - 1 && fri_data[i + 1][j] == 0) {
		com = abs(data[i][j] - data[i + 1][j]);
		if (com >= L && com <= R) { fri_data[i + 1][j] = count; Move(data, fri_data, L, R, i + 1, j); }
	}
	if (j < n - 1 && fri_data[i][j + 1] == 0) {
		com = abs(data[i][j] - data[i][j + 1]);
		if (com >= L && com <= R) { fri_data[i][j + 1] = count; Move(data, fri_data, L, R, i, j + 1); }
	}

}

vector<pair<int, int>> Make_fri(vector<vector<int>>& data, vector<vector<int>>& fri_data, int L, int R) {


	//0부터 n,n까지 만약 이웃이 국경을 열수 있다면 이웃이 같은 fri값 가짐
	//이웃이 fri값을 가지면 이웃도 같이 확인하기
	//계속 진행하면서 fri값을 가졌으면 con
	int count = 1;
	int n = data.size();
	vector<pair<int, int>> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (fri_data[i][j] != 0) {
				answer[fri_data[i][j] - 1].first += data[i][j];
				answer[fri_data[i][j] - 1].second += 1;
				continue;
			}
			fri_data[i][j] = count;
			answer.push_back({ data[i][j], 1 });
			Move(data, fri_data, L, R, i, j);
			count += 1;

		}
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout.tie(NULL);
	//vector<vector<pair<int,int>>> pos
	//vector<vector<int>> data
	//vector<vector<int>> fri_data
	//n L, R 받기
	int n, L, R = 0;
	cin >> n;
	cin >> L;
	cin >> R;
	vector<int> in(n);
	vector<vector<int>> data(n, in);
	vector<vector<int>> fri_data(n, in);

	vector<pair<int, int>> fri_sum;
	int input = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			data[i][j] = input;
		}
	}
	fri_sum = Make_fri(data, fri_data, L, R);
	int count = 0;
	//fri_num != n*n + 1
	while (fri_sum.size() != n * n) {
		//나라별로 합 진행하기
		//min, max차가 r-l과 적거나 같다면 끝

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				{ data[i][j] = fri_sum[fri_data[i][j] - 1].first / fri_sum[fri_data[i][j] - 1].second; }
				fri_data[i][j] = 0;
			}
		}


		fri_sum = Make_fri(data, fri_data, L, R);
		//cout << fri_sum.size() << endl;
		count += 1;
	}
	cout << count;
	return 0;
}