#include <iostream>
using namespace std;
#include <cstring>


int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    int input;
    cin >> input;
    string odd_order = "*";
    string even_order = "";
    for (int i = 0; i < (input - 1) / 2; i++) {
        odd_order += " *";
    }
    for (int i = 0; i < input / 2; i++) {
        even_order += " *";
    }

    for (int i = 0; i < input; i++) {
        cout << odd_order << "\n";
        cout << even_order << "\n";
    }
    return 0;
}