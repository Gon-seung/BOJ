#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int input = 0;
    cin >> input;
    int div = 5;
    while (div <= input) {
        answer += input / div;
        div *= 5;
    }
    cout << answer;

    return 0;
}
