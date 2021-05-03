#include <iostream>
using namespace std;
#include <cstring>


int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    int size = 0;
    cin >> size;
    string input = "";
    int contin = 0;
    int grade = 0;
    for (int i = 0; i < size; i++) {
        cin >> input;
        contin = 0;
        grade = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == 'O') {
                grade += 1 + contin;
                contin += 1;
            }
            else if (input[i] == 'X') { contin = 0; }
        }
        cout << grade << "\n";
    }
    return 0;
}