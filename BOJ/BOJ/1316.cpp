#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    int num;
    cin >> num;

    string input;

    int answer = 0;

    bool check_right = true;
    for (int i = 0; i < num; i++) {
        cin >> input;
        check_right = true;
        vector<bool> data('z' - 'a' + 1, true);
        for (int j = 1; j < input.size(); j++) {
            if (input[j - 1] != input[j]) {
                if (data[input[j] - 'a'] == false) { check_right = false; break; }
                else { data[input[j] - 'a'] = false; }
            }
            if (j == 1) { data[input[0] - 'a'] = false; }
        }
        if (check_right) { answer += 1; }
    }
    cout << answer;
    return 0;
}