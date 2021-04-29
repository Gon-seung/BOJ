#include <iostream>
#include <vector>

using namespace std;

int Root(int num) {
	int min = 0;
	int max = num;
	int answer = (min + max + 1) / 2;
	while (true) {
		//cout << min << " " << max << " " << answer << "\n";
		if (answer * answer <= num && (answer + 1) * (answer * 1) > num) { return answer; }
		else if (answer * answer <= num) { min = answer; }
		else { max = answer; }
		answer = (min + max + 1) / 2;
	}

}

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	//n ¹Þ±â
	int m, n = 0;
	cin >> m;
	cin >> n;

	vector<bool> check(n + 1);

	check[0] = true;

	check[1] = true;

	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}
	return 0;
}

