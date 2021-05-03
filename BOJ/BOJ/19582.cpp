#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;
	cin >> n;
	long long sum = 0;
	long long max = -1;
	long long max2 = -1;
	bool del = false;
	bool zzz = false;
	while (n > 0) {
		n -= 1;
		long long x, p;
		cin >> x >> p;
		if (sum <= x) {
			sum += p;
			if (max < p) { max2 = max; max = p; }
		}
		else if (del) { zzz = true; break; }
		else {
			del = true;
			if (sum - max <= x && max > p) {
				sum -= max;
				sum += p;
			}
		}
	}
	if (zzz) { cout << "Zzz"; }
	else { cout << "Kkeo-eok"; }
	return 0;
}