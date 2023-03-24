#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    int num1 = 0;
    cin >> num1;

    int answer = 0;

    if (num1 % 5 == 1) { num1 -= 6; answer += 2; }
    else if (num1 % 5 == 2) { num1 -= 12; answer += 4; }
    else if (num1 % 5 == 3) { num1 -= 3; answer += 1; }
    else if (num1 % 5 == 4) { num1 -= 9; answer += 3; }
    if (num1 < 0) { answer = -1; }
    else { answer += num1 / 5; }


    cout << answer;
    return 0;
}