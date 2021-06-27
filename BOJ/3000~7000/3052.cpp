#include <iostream>
using namespace std;
#include <vector>


int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    vector<int> data(42);

    int input;
    for (int i = 0; i < 10; i++) {
        cin >> input;
        data[input % 42] += 1;
    }

    int count = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] > 0) { count += 1; }
    }
    cout << count << "\n";

    return 0;
}