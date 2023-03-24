#include <iostream> 
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Jew {

public:
	int kg;
	int price;
};

bool Compare(Jew a, Jew b) {
	return a.kg < b.kg;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	int n = 0, k = 0;
	cin >> n >> k;
	vector<Jew> data(n);
	for (int i = 0; i < n; i++) {
		cin >> data[i].kg;
		cin >> data[i].price;
	}
	sort(data.begin(), data.end(), Compare);

	vector<int> bag(k);
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(bag.begin(), bag.end());
	long long answer = 0;
	int pos = 0;
	int kgpos = 0;
	multiset<int> sum_price;
	while (pos < k) {
		while (kgpos < n && data[kgpos].kg <= bag[pos]) {
			sum_price.insert(data[kgpos].price);
			if (sum_price.size() > k) { sum_price.erase(sum_price.begin()); }
			kgpos += 1;
		}
		pos += 1;
		if (sum_price.size() == 0) { continue; }
		answer += *(--sum_price.end());
		sum_price.erase(--sum_price.end());
	}
	cout << answer;

	return 0;
}