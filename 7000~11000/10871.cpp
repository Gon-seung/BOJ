#include <iostream>
using namespace std;
#include <vector>

int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);
    int x, n;
    cin >> n;
    cin >> x;

    vector<int> seq(n);
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        seq[i] = a;
    }
    for (int i = 0; i < n; i++) {
        if (seq[i] < x) { cout << seq[i] << " "; }
    }

    return 0;
}