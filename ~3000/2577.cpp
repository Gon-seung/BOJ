#include <iostream>
using namespace std;
#include <vector>


int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    vector<int> data(10);

    int input;
    int value = 1;
    for (int i = 0; i < 3; i++) {
        cin >> input;
        value *= input;
    }

    while (value != 0) {
        data[value % 10] += 1;
        value = value / 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << data[i] << "\n";
    }
    return 0;
}