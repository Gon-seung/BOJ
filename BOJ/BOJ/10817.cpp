#include <iostream>
using namespace std;
#include <set>

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    multiset<int> data;
    int input;
    for (int i = 0; i < 3; i++) {
        cin >> input;
        data.insert(input);
    }
    data.erase(data.begin());
    cout << *data.begin();
    return 0;
}