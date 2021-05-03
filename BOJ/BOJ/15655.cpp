#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n = 0;
int m = 0;

bool Check_answer(vector<bool> answer) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (answer[i]) { num += 1; }
        if (num > m) { return false; }
    }
    if (num < m) { return false; }
    return true;
}

void Print(vector<int>& data, vector<bool> answer, int pos) {
    if (Check_answer(answer)) {
        for (int i = 0; i < data.size(); i++) {
            if (answer[i]) { cout << data[i] << " "; }
        }
        cout << "\n";
        return;
    }
    for (int i = pos; i < data.size(); i++) {
        answer[i] = true;
        pos = i + 1;
        Print(data, answer, pos);
        answer[i] = false;
    }

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        int input = 0;
        cin >> input;
        data[i] = input;
    }
    vector<bool> answer(n, false);
    sort(data.begin(), data.end());
    Print(data, answer, 0);

    return 0;
}
