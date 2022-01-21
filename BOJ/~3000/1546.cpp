#include <iostream>
using namespace std;
#include <vector>


int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    int num;
    cin >> num;
    vector<double> data(num);

    double input = 0.0;
    for (int i = 0; i < num; i++) {
        cin >> input;
        data[i] = input;
    }

    int max = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] > max) { max = data[i]; }
    }
    double total = 0;
    for (int i = 0; i < data.size(); i++) {
        data[i] = data[i] / max * 100;
        total = total + data[i];
    }
    total /= data.size();
    cout << total << "\n";
    return 0;
}