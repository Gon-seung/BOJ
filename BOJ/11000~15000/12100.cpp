//양식 저장용

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

vector<int> Sort(vector<int> data, int N) {
	vector<int> answer;
	bool sum_next = false;
	for (int i = 0; i < data.size(); i++) {
		if (sum_next) { sum_next = false;  continue; }
		else if ((i != data.size() - 1) && data[i] == data[i + 1]) { answer.push_back(data[i] * 2); sum_next = true; }
		else { answer.push_back(data[i]); }

	}
	for (int i = answer.size(); i < N; i++) {
		answer.push_back(0);
	}
	return answer;

}

int main() {
	cin.tie();

	int N = 0;
	cin >> N;

	int num = 0;
	int max = 0;
	vector<int> Q(N);
	vector<vector<int>> data(N, Q);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (max < num) { max = num; }
			data[i][j] = num;
		}
	}

	vector<vector<int>> new_data(data);
	vector<int> line;
	vector<int> new_line;
	int order = 0;
	//4 * 4 * 4 * 4 * 4
	for (int i = 0; i < 1024; i++) {
		order = i;
		data = new_data;
		//bool check;
		//if (256 + 128 + 32 + 8 + 2 == order) { check = true; }
		//else { check = false; }

		while (order != 0) {
			if (order % 4 == 0) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						if (data[k][j] != 0) { line.push_back(data[k][j]); }
					}
					new_line = Sort(line, N);
					for (int k = 0; k < N; k++) {
						{ data[k][j] = new_line[k]; }
					}
					line.clear();
				}
			}
			else if (order % 4 == 1) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						if (data[N - 1 - k][N - 1 - j] != 0) { line.push_back(data[N - 1 - k][N - 1 - j]); }
					}
					new_line = Sort(line, N);

					for (int k = 0; k < N; k++) {
						{ data[N - 1 - k][N - 1 - j] = new_line[k]; }
					}
					line.clear();
				}
			}
			else if (order % 4 == 2) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						if (data[N - 1 - j][N - 1 - k] != 0) { line.push_back(data[N - 1 - j][N - 1 - k]); }
					}
					new_line = Sort(line, N);

					for (int k = 0; k < N; k++) {
						{ data[N - 1 - j][N - 1 - k] = new_line[k]; }
					}
					line.clear();
				}
			}
			else if (order % 4 == 3) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						if (data[j][k] != 0) { line.push_back(data[j][k]); }
					}
					new_line = Sort(line, N);

					for (int k = 0; k < N; k++) {
						{ data[j][k] = new_line[k]; }
					}
					line.clear();
				}
			}
			order /= 4;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (data[j][k] > max) { max = data[j][k]; }
					//if (check) { cout << data[j][k]; }
				}
				//if(check) cout << endl;
			}
			//if(check) cout << endl;
		}
	}
	cout << max;
	return 0;
}


