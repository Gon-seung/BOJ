#include <iostream>
using namespace std;
#include <cstring>

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;

    string a = "*";
    string b = " ";
    for (int i = 0; i < x; i++) {
        a += '*';
        b += ' ';
    }
    for (int i = 1; i <= x; i++) {
        cout << b.substr(0, x - i) << a.substr(x - i, i) << "\n";
    }

    return 0;
}