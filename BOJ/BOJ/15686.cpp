#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	//N,M 받기
	int N, M = 0;
	cin >> N;
	cin >> M;
	//data 받기
	//vector<vector<int>> chi 치킨집 좌표들 받기
	vector<vector<int>> data(N);
	vector<vector<int>> chi;
	vector<vector<int>> house;
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			data[i].push_back(input);
			if (input == 2) { chi.push_back({ i,j }); }
			if (input == 1) { house.push_back({ i,j }); }
		}
	}

	//0부터 1 << chi.size 까지
	//1의 개수가 M과 다르면 continue
	int check = 0;
	int min = 2 * N * house.size();
	int min_compare = 0;
	for (int i = 0; i < 1 << chi.size(); i++) {
		min_compare = 0;
		check = i;
		int count = 0;
		int chi_count = 0;
		vector<vector<int>> new_chi;
		while (check != 0) {
			if (check % 2 == 1) {
				new_chi.push_back(chi[chi_count]);
				count += 1;
			}
			chi_count += 1;
			check /= 2;
		}
		if (count != M) { continue; }


		for (int j = 0; j < house.size(); j++) {
			int min_dis = 2 * N;
			for (int k = 0; k < new_chi.size(); k++) {
				int x = house[j][0] - new_chi[k][0];
				if (x < 0) { x = -x; }
				int y = house[j][1] - new_chi[k][1];
				if (y < 0) { y = -y; }
				if (min_dis > x + y) { min_dis = x + y; }
			}
			min_compare += min_dis;
		}
		//cout << i << ":" << min_compare << endl;
		if (min > min_compare) { min = min_compare; }
	}
	cout << min;
	//
	return 0;
}
