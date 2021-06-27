#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

vector<int> input;
vector<int> tree(1000000, 0);

void init(int node, int start, int end) {
	if (start == end) tree[node] = input[start];
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

ll query(int node, int start, int end, int i, int j) {
	if (j < start || end < i) return 0;
	if (i <= start && end <= j) return tree[node];
	ll m1 = query(node * 2, start, (start + end) / 2, i, j);
	ll m2 = query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	return m1 + m2;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0;
	cin >> n >> m;
	input = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		cout << query(1, 1, n, start, end) << "\n";
	}
	return 0;
}