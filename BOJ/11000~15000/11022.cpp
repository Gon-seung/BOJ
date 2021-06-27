#include <iostream>
using namespace std;

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;

    int a = 0, b = 0;
    for (int i = 0; i < x; i++) {
        cin >> a;
        cin >> b;
        cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << "\n";
    }

    return 0;
}