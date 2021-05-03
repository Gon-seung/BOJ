#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    string input;
    cin >> input;

    int answer = 0;
    vector<string> data = { "c=","c-","d-","lj", "nj","s=","z=" };

    string check = "";
    int pos = 0;
    while (pos < input.size()) {
        for (int j = 0; j < data.size(); j++) {
            if (input.substr(pos, 2) == data[j]) { pos += 1; }
        }
        if (input.substr(pos, 3) == "dz=") { pos += 2; }

        answer += 1;
        pos += 1;

    }
    cout << answer;
    return 0;
}