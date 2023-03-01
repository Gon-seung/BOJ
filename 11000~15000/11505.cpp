#include <iostream> 
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> input;
vector<ll> tree(10000000, 0);

void init(int node, int start, int end) {
	if (start == end) tree[node] = input[start];
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
	}
}

//i j는 구하고자 하는 지점.
ll query(int node, int start, int end, int i, int j) {
	if (j < start || end < i) return 1;
	if (i <= start && end <= j) return tree[node];
	ll m1 = query(node * 2, start, (start + end) / 2, i, j);
	ll m2 = query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	return (m1 * m2) % 1000000007;
}

void update(int node, int start, int end, int index, int value) {
	if (index < start || end < index)
		return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, value);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	input = vector<ll>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		int choose, start, end;
		cin >> choose >> start >> end;
		if (choose == 1) { update(1, 1, n, start, end); }
		else { cout << (query(1, 1, n, start, end) % 1000000007) << "\n"; }
	}
	return 0;
}