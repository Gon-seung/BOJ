#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n = 0;
int m = 0;

void Print(vector<int> data, string a) {
    if (data.size() == n - m) {

        cout << a << "\n";
    }
    else {
        for (int i = 0; i < data.size(); i++) {
            vector<int> new_data = data;
            string new_a = "";
            if (a == "") {
                new_a = to_string(new_data[i]);
            }
            else { new_a = a + " " + to_string(new_data[i]); }
            new_data.erase(new_data.begin() + i);
            Print(new_data, new_a);

        }

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
    sort(data.begin(), data.end());
    Print(data, "");

    return 0;
}
