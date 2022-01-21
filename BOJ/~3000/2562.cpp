#include <iostream>
using namespace std;
#include <vector>


int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    vector<int> data(9);
    for (int i = 0; i < data.size(); i++) {
        cin >> data[i];
    }

    int pos = 0;
    int max = data[0];

    for (int i = 0; i < data.size(); i++) {
        if (data[i] > max) { max = data[i]; pos = i; }
    }
    cout << max << "\n";
    cout << pos + 1 << "\n";
    return 0;
}