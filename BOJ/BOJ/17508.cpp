#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    cin.tie();

    int x = 0;
    int y = 0;
    cin >> x;
    cin >> y;
    vector<int> in_data(y, 0);
    vector<vector<int>> data(x, in_data);
    string input;
    for (int i = 0; i < x; i++) {

        cin >> input;
        for (int j = 0; j < y; j++) {
            data[i][j] = (int)input[j] - '0';
            //cout << data[i][j] << " " << input[j] << endl;;
        }
    }

    int answer = 0;
    vector<int> pair(2);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            pair[0] = data[i][j];
            pair[1] = data[x - i - 1][y - j - 1];
            if (i == x - i - 1 && j == y - j - 1) {
                if (pair[0] == 8) { continue; }
                else { answer = -1; break; }
            }
            if (pair[0] > pair[1]) {
                int tmp = pair[0];
                pair[0] = pair[1];
                pair[1] = tmp;
            }
            switch (pair[0]) {
            case 6: {
                if (pair[1] == 6) { answer += 1; }
                else if (pair[1] != 9) { answer = -1; }
                break;
            }
            case 7: {
                if (pair[1] == 7) { answer += 1; }
                else { answer = -1; }
                break;
            }
            case 8: {
                if (pair[1] == 9) { answer = -1; }
                break;
            }
            case 9: {answer += 1;  break; }
            }
            //cout << pair[0] << " " << pair[1] << " " <<  answer<<endl;
            if (answer == -1) { goto end; }
        }
        if (answer == -1) { goto end; }
    }
    if (answer % 2 == 0) {
        answer /= 2;
    }
    else { answer = (answer - 1) / 2 + 1; }
end:
    cout << answer;

    return 0;
}