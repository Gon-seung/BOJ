#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    int x;
    string num;
    cin >> x;
    cin >> num;

    int total = 0;
    for (int i = 0; i < x; i++) {
        total += stoi(num.substr(i, 1));
    }
    cout << total;
    return 0;
}