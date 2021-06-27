#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	//T ¹Þ±â
	int T;
	cin >> T;
	long long count = 1;

	for (int i = 0; i < T; i++) {
		int x, y = 0;
		cin >> x;
		cin >> y;
		long long min = 0;
		long long max = y - x;
		while (true) {
			count = (min + max + 1) / 2;
			//cout << min << " " << max << " " << count << endl;
			if ((count * count + 2 * count + 1) / 4 < y - x) { min = count; }
			else if ((count * count + 2 * count + 1) / 4 >= y - x && count * count / 4 < y - x) { break; }
			else { max = count; }

		}
		cout << count << "\n";
	}



	return 0;
}
