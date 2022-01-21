#include <iostream>
using namespace std;

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int origin = 0, left = 0, right = 0;

    int count = 0;
    cin >> origin;
    left = origin / 10;
    right = origin % 10;

    int tmp;

    do {
        tmp = right;
        right = (left + right) % 10;
        left = tmp;
        count += 1;
    } while (origin != left * 10 + right);

    cout << count << "\n";
    return 0;
}