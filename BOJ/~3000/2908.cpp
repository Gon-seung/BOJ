#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    string x;
    string y;

    cin >> x;
    cin >> y;

    string x_reverse(x);
    string y_reverse(y);
    for (int i = 0; i < x.size(); i++) {
        x_reverse[i] = x[x.size() - 1 - i];
    }
    for (int i = 0; i < y.size(); i++) {
        y_reverse[i] = y[y.size() - 1 - i];
    }

    if (stoi(x_reverse) > stoi(y_reverse)) { cout << x_reverse << '\n'; }
    else { cout << y_reverse << '\n'; }

    return 0;
}