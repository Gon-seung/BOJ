#include <iostream>
using namespace std;

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;

    int* c = new int[x];
    int a = 0, b = 0;
    for (int i = 0; i < x; i++) {
        cin >> a;
        cin >> b;
        c[i] = a + b;
    }
    for (int i = 0; i < x; i++) {
        cout << c[i] << "\n";
    }

    delete[]c;
    return 0;
}