#include <iostream>
using namespace std;
#include <cstring>

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;

    string a = "*";
    for (int i = 0; i < x; i++) {
        a += '*';
    }
    for (int i = 1; i <= x; i++) {
        cout << a.substr(0, i) << "\n";
    }

    return 0;
}