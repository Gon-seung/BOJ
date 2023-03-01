#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	int T;
	cin >> T;

	int H = 0;
	int W = 0;
	int N = 0;
	for (int i = 0; i < T; i++) {
		cin >> H;
		cin >> W;
		cin >> N;
		string a = "";
		string b = "";
		if ((N - 1) / H + 1 < 10) { b = "0" + to_string(((N - 1) / H + 1)); }
		else { b = to_string((N - 1) / H + 1); }
		if (N % H == 0) { a = to_string(H); }
		else { a = to_string(N % H); }

		cout << a << b << endl;
	}

	return 0;
}
