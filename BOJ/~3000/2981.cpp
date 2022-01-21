#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Gcd(int a, int b) {
    if (a == 0) { return b; }
    else if (b == 0) { return a; }
    else if (a > b) {
        return Gcd(a % b, b);
    }
    else { return Gcd(a, b % a); }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);
    int n = 0;
    cin >> n;

    vector<long long> data(n);
    vector<long long> sub_data(n);
    for (int i = 0; i < n; i++) {
        long long input = 0;
        cin >> input;
        data[i] = input;
    }
    long long max = 0;
    sort(data.begin(), data.end());
    for (int i = 0; i < n - 1; i++) {
        sub_data[i] = data[i + 1] - data[i];
    }
    for (int i = 0; i < n - 1; i++) {
        max = Gcd(max, sub_data[i]);
    }
    int i;
    vector<long long> answer;
    for (i = 2; (long long)i * i < max; i++) {
        if (max % i == 0) { answer.push_back(i); answer.push_back(max / i); }
    }
    if ((long long)i * i == max) { answer.push_back(i); }
    answer.push_back(max);
    sort(answer.begin(), answer.end());
    for (int j = 0; j < answer.size(); j++) {
        cout << answer[j] << " ";
    }
    return 0;
}