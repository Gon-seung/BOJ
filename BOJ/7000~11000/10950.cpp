#include <iostream>
using namespace std;

int main(void) {
    int x;
    cin >> x;

    int a, b;
    for (int i = 0; i < x; i++) {
        cin >> a;
        cin >> b;
        cout << a + b << endl;
    }
    return 0;
}