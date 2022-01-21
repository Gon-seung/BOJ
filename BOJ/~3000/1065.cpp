#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool Check(string a) {
    if (a.size() == 1) { return true; }

    int value = a[0] - a[1];
    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] - a[i + 1] != value) { return false; }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (Check(to_string(i))) { count += 1; }
    }
    cout << count;
    return 0;
}