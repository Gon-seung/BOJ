#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    int num;
    cin >> num;

    int repeat;
    string input;
    for (int i = 0; i < num; i++) {
        cin >> repeat;
        cin >> input;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < repeat; j++) {
                cout << input[i];
            }

        }
        cout << "\n";
    }


    return 0;
}