#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;



int main() {
    vector<int> a1(10);
    vector<int> a2(10);
    vector<int> a3(10);
    vector<int> a4(10);
    //a1 1의자리 , a2 10의자리, a3 100의자리
    for (int i = 0; i < 10; i++) {
        a1[i] = 2 * i;
        a2[i] = 11 * i;
        a3[i] = 101 * i;
        a4[i] = 1001 * i;
    }

    vector<int> data;
    for (int x1 = 0; x1 < 10; x1++) {
        for (int x2 = 0; x2 < 10; x2++) {
            for (int x3 = 0; x3 < 10; x3++) {
                for (int x4 = 0; x4 < 10; x4++) {
                    data.push_back(a1[x1] + a2[x2] + a3[x3] + a4[x4]);
                }
            }
        }
    }
    sort(data.begin(), data.end());
    set<int> data_sort;
    for (int i = 0; i < data.size(); i++) {
        data_sort.insert(data[i]);
    }
    int start = 1;
    data_sort.erase(data_sort.begin());
    while (start < 10000) {
        if (data_sort.size() == 0) { cout << start << endl; }
        else {
            if (start != *data_sort.begin()) { cout << start << "\n"; }
            else { data_sort.erase(data_sort.begin()); }
        }
        start += 1;
    }
    return 0;
}