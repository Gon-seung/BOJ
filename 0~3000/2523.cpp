#include <iostream>
using namespace std;
#include <cstring>

void show_star(int a) {
    string answer = "";
    for (int i = 0; i < a; i++) {
        answer += '*';
    }
    cout << answer << "\n";
}
int main(void) {

    cin.tie();
    ios_base::sync_with_stdio(false);

    int input;
    cin >> input;
    for (int i = 1; i <= input; i++) {
        show_star(i);
    }
    for (int i = input - 1; i > 0; i--) {
        show_star(i);
    }
    return 0;
}