#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int a = n, b = m;
    while (a != 0 && b != 0) {
        if (a > b) { a = a % b; }
        else { b = b % a; }
    }
    if (b == 0) { cout << a << "\n" << a * (n / a) * (m / a); }
    else { cout << b << "\n" << b * (n / b) * (m / b); }

    return 0;
}