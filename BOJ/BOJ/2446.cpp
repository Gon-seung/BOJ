#include <iostream>
using namespace std;
#include <cstring>


int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    int input;
    cin >> input;
    string show = "";
    string show_blank = "";
    for (int i = 0; i < input * 2 - 1; i++) {
        show += "*";
        show_blank += " ";
    }
    for (int i = 0; i < input; i++) {
        cout << show_blank.substr(0, i) << show.substr(i, 2 * input - 2 * i - 1) << "\n";
    }
    for (int i = input - 2; i >= 0; i--) {
        cout << show_blank.substr(0, i) << show.substr(i, 2 * input - 2 * i - 1) << "\n";
    }
    return 0;
}