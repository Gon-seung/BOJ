#include <iostream>
using namespace std;

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    int cheap_ham = -1; int cheap_dri = -1;
    int input;

    for (int i = 0; i < 3; i++) {
        cin >> input;
        if (cheap_ham == -1 || cheap_ham > input) { cheap_ham = input; }
    }
    for (int i = 3; i < 5; i++) {
        cin >> input;
        if (cheap_dri == -1 || cheap_dri > input) { cheap_dri = input; }
    }
    cout << cheap_ham + cheap_dri - 50 << "\n";
    return 0;
}