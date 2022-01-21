#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    int num1 = 0;
    cin >> num1;

    int answer = 1;
    int n = 0;
    while (true) {
        if (num1 == 1) { break; }
        if (num1 <= 1 + 6 * n * (n + 1) / 2) { answer = n + 1; break; }
        else { n += 1; }
    }



    cout << answer;
    return 0;
}