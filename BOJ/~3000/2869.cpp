#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

int main() {
	cin.tie();

	int A = 0;
	int B = 0;
	int V = 0;
	int day = 0;
	cin >> A;
	cin >> B;
	cin >> V;

	int hei = 0;
	day = (V - A) / (A - B);
	hei = (A - B) * day;
	while (true) {
		day += 1;
		hei += A;
		if (hei >= V) { break; }
		else { hei -= B; }
	}
	cout << day;
	return 0;
}
