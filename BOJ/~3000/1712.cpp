#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    cin >> num1;
    cin >> num2;
    cin >> num3;

    int answer = 0;
    if (num2 >= num3) { answer = -1; }
    if (answer != -1) { answer = num1 / (num3 - num2) + 1; }

    cout << answer;
    return 0;
}