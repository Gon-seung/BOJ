#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Gcd(int a, int b) {
    if (a == 0) { return b; }
    else if (b == 0) { return a; }
    else if (a > b) {
        return Gcd(a % b, b);
    }
    else { return Gcd(a, b % a); }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int n = 0, r = 0;
    cin >> n;
    cin >> r;
    for (int i = 0; i < n - 1; i++) {
        int r1 = 0;
        cin >> r1;
        cout << r / Gcd(r, r1) << "/" << r1 / Gcd(r, r1) << "\n";
    }

    return 0;
}