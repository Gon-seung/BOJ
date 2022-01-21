#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    string num;
    cin >> num;

    int len = 'z' - 'a' + 1;
    vector<int> data(len, -1);
    for (int i = 0; i < num.size(); i++) {
        if (data[num[i] - 'a'] == -1) { data[num[i] - 'a'] = i; }
    }

    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }

    return 0;
}