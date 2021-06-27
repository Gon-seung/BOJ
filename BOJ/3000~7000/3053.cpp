#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);

	double pi = 3.14159265358979323846264;
	int R = 0;
	cin >> R;
	double size1 = pi * R * R;
	int size2 = 2 * R * R;
	printf("%.6f\n", size1);
	printf("%d", size2);

	return 0;
}