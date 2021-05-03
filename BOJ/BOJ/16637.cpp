#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n = 0;
string input1 = "";

int Compute(string input) {
    if (input.size() == 0) { return 0; }
    int answer = stoi(input.substr(0, 1));
    for (int i = 2; i < input.size(); i += 2) {
        if (input[i - 1] == '+') { answer += stoi(input.substr(i, 1)); }
        if (input[i - 1] == '-') { answer -= stoi(input.substr(i, 1)); }
        if (input[i - 1] == '*') { answer *= stoi(input.substr(i, 1)); }
    }
    return answer;

}

void Find_max(vector<int>& answer, int pos, vector<int>& answer_min) {
    if (pos >= answer.size()) { return; }
    int max_pos = Compute(input1.substr(0, 2 * pos + 1));
    int min_pos = Compute(input1.substr(0, 2 * pos + 1));

    if (pos > 0 && input1[2 * pos - 1] == '+') {
        max_pos = answer[pos - 1] + stoi(input1.substr(pos * 2, 1)); min_pos = answer_min[pos - 1] + stoi(input1.substr(pos * 2, 1));
    }
    if (pos > 0 && input1[2 * pos - 1] == '-') {
        max_pos = answer[pos - 1] - stoi(input1.substr(pos * 2, 1)); min_pos = answer_min[pos - 1] - stoi(input1.substr(pos * 2, 1));
    }
    if (pos > 0 && input1[2 * pos - 1] == '*') {
        max_pos = answer[pos - 1] * stoi(input1.substr(pos * 2, 1)); min_pos = answer_min[pos - 1] * stoi(input1.substr(pos * 2, 1));
    }

    if (pos >= 2) {
        int aft = Compute(input1.substr(2 * pos - 2, 3));
        if (input1[2 * pos - 3] == '+') {
            max_pos = max(max_pos, answer[pos - 2] + aft); min_pos = min(min_pos, answer_min[pos - 2] + aft);
        }
        if (input1[2 * pos - 3] == '-') {
            max_pos = max(max_pos, answer[pos - 2] - aft); min_pos = min(min_pos, answer_min[pos - 2] - aft);
        }
        if (input1[2 * pos - 3] == '*') {
            max_pos = max(max_pos, answer[pos - 2] * aft); min_pos = min(min_pos, answer_min[pos - 2] * aft);
        }

        if (input1[2 * pos - 3] == '*' && answer_min[pos - 2] * aft > max_pos) {
            max_pos = answer_min[pos - 2] * aft;
        }
        if (input1[2 * pos - 3] == '*' && answer[pos - 2] * aft < min_pos) {
            min_pos = answer[pos - 2] * aft;
        }
        //cout << " " << aft << endl;
    }
    answer[pos] = max_pos;
    answer_min[pos] = min_pos;
    //cout << pos << " " << max_pos << endl;
    Find_max(answer, pos + 1, answer_min);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<int> data(n);
    cin >> input1;
    vector<int> answer((n + 1) / 2);
    vector<int> answer_min((n + 1) / 2);
    Find_max(answer, 0, answer_min);

    cout << answer[answer.size() - 1];
    return 0;
}
