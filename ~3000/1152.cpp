#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    string a;
    getline(cin, a);

    int answer = 0;
    string check = "";
    for (int i = 0; i < a.size(); i++) {

        if (a[i] == ' ' && check.size() > 0) { answer += 1; check = ""; }

        else if (a[i] != ' ') { check += a[i]; }
    }
    if (check.size() != 0) { answer += 1; }
    cout << answer;
    return 0;
}