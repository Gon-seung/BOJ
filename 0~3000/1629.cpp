#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int remain(long long a, long long b, long long c) {
	if (b == 0) { return 1; }
	else if (b % 2 == 0) {
		long long value = remain(a, b / 2, c);
		return (value * value % c);
	}
	else {
		return (remain(a, b - 1, c) * a) % c;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	long long a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	cout << remain(a, b, c);

	return 0;
}