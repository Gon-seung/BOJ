#include <iostream>
using namespace std;

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;

    for (int i = x; i > 0; i--) {
        cout << i << "\n";
    }

    return 0;
}