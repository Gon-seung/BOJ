#include <iostream>
using namespace std;

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a;
    cin >> b;

    while (a && b) {
        cout << a + b << "\n";
        cin >> a;
        cin >> b;
    }


    return 0;
}