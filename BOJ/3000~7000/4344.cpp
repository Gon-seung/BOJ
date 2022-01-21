#include <iostream>
using namespace std;
#include <vector>


int main(void) {

    cin.tie();

    int size = 0;
    cin >> size;

    int num = 0;
    double aver = 0.0;
    double rate = 0.0;
    int input = 0;
    for (int i = 0; i < size; i++) {
        cin >> num;
        vector<int> grades(num);
        aver = 0.0;
        rate = 0.0;
        for (int j = 0; j < num; j++) {
            cin >> input;
            grades[j] = input;
            aver += input;
        }
        aver /= num;
        for (int j = 0; j < num; j++) {
            if (grades[j] > aver) {
                rate += 100.0 / num;
            }
        }
        printf("%.3f%%\n", rate);
    }

    return 0;
}