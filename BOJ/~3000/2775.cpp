#include <iostream>
#include <vector>

using namespace std;

int Value(int k, int n) {
	int answer = 0;
	if (k == 0) { answer = n; }
	else {
		for (int i = 1; i <= n; i++) {
			answer += Value(k - 1, i);
		}
	}
	return answer;

}

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	//T ¹Þ±â
	int T;
	cin >> T;
	//k,n
	for (int i = 0; i < T; i++) {
		int k, n = 0;
		cin >> k;
		cin >> n;
		cout << Value(k, n) << "\n";
	}



	return 0;
}
