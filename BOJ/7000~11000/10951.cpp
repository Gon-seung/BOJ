#include <iostream>
using namespace std;

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int a = 0, b = 0;

    while (cin >> a) {

        cin >> b;
        cout << a + b << "\n";
    }


    return 0;
}