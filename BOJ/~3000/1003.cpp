#include <iostream>
#include <vector>

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;

	vector<vector<int>> fibo;
	vector<int> input;
	//1번째 0호출양, 2번째 1 호출양
	fibo = { {1,0}, {0,1} };
	int max = 0;
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		input.push_back(a);
		if (a > max) {
			max = a;
		}
	}
	for (int i = 2; i <= max; i++) {
		fibo.push_back({ fibo[fibo.size() - 1][0] + fibo[fibo.size() - 2][0], fibo[fibo.size() - 1][1] + fibo[fibo.size() - 2][1] });
	}
	for (int i = 0; i < n; i++) {
		cout << fibo[input[i]][0] << " " << fibo[input[i]][1] << "\n";
	}
	return 0;
}