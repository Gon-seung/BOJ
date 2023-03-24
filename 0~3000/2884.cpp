#include <iostream>
using namespace std;

int main(void) {
    int h, m;
    cin >> h;
    cin >> m;

    int time = 60 * h + m;
    time -= 45;
    if (time < 0) { time += 60 * 24; }

    cout << time / 60 << " " << time % 60;
    return 0;
}