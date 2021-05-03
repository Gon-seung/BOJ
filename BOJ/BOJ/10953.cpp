#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num = 0;
	cin >> num;
	while (num > 0) {
		num -= 1;
		char n[4];
		cin >> n;
		cout << atoi(&n[0]) + atoi(&n[2]) << "\n";
	}
	return 0;
}