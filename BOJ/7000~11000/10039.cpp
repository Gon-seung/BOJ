#include <iostream>
using namespace std;
#include <vector>

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    vector<int> data(5);
    int aver = 0;
    for (int i = 0; i < 5; i++) {
        cin >> data[i];
        if (data[i] < 40) { aver += 40; }
        else {
            aver += data[i];
        }
    }
    aver /= 5;
    cout << aver << "\n";
    return 0;
}