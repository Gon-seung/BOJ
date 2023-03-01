#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    int size = 'z' - 'a' + 1;
    vector<int> data(size);

    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= 'a') { data[input[i] - 'a'] += 1; }
        else { data[input[i] - 'A'] += 1; }
    }

    char answer;
    int max_num = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] > max_num) { answer = i + 'A'; max_num = data[i]; }
        else if (data[i] == max_num) { answer = '?'; }
    }
    cout << answer;
    return 0;
}