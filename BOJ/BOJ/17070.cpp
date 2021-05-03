#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    vector<vector<int>> data(n, vector<int>(n, 0));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input = 0;
            cin >> input;
            data[i][j] = input;
        }
    }

    vector<vector<int>> ver(n, vector<int>(n, 0));
    vector<vector<int>> hei(n, vector<int>(n, 0));
    vector<vector<int>> hal(n, vector<int>(n, 0));
    ver[0][1] = 1;

    vector<pair<int, int>> pos;
    pos.push_back({ 0,1 });
    for (int i = 2; i < 2 * n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            if (j < n && i - j < n && i - j > 0 && data[j][i - j] == 0) {
                ver[j][i - j] = hal[j][i - 1 - j] + ver[j][i - 1 - j];
                hei[j][i - j] = 0;
                hal[j][i - j] = 0;
                if (j - 1 >= 0) {
                    hei[j][i - j] += hal[j - 1][i - j] + hei[j - 1][i - j];
                }
                if (j - 1 >= 0 && data[j - 1][i - j] == 0 && data[j][i - j - 1] == 0) {
                    hal[j][i - j] += hal[j - 1][i - j - 1] + hei[j - 1][i - j - 1] + ver[j - 1][i - j - 1];
                }
                //cout << j << " " << i - j << " " << ver[j][i - j] << " " << hal[j][i - j] << " " << hei[j][i - j] << endl;
            }
        }
    }
    cout << hei[n - 1][n - 1] + ver[n - 1][n - 1] + hal[n - 1][n - 1];
    return 0;
}
