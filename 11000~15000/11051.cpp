#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Calculate(int n, int m, vector<vector<int>>& data) {
    if (m == 0) { data[n][m] = 1; return 1; }
    if (n == m) { data[n][m] = 1; return 1; }

    if (data[n][m] != -1) { return data[n][m]; }
    int answer = Calculate(n - 1, m - 1, data) + Calculate(n - 1, m, data);
    data[n][m] = answer % 10007;
    return answer % 10007;
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    vector<vector<int>> data(n + 1, vector<int>(m + 1, -1));
    cout << Calculate(n, m, data) % 10007;


    return 0;
}