#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {
    cin.tie();

    string x;

    cin >> x;

    int answer = 0;
    vector<int> data = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
    for (int i = 0; i < x.size(); i++) {
        answer += data[x[i] - 'A'];
    }
    cout << answer;
    return 0;
}