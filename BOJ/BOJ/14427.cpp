#include <iostream> 
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, k, m;

vector<int> input;
vector<int> segment_tree(1000000, 0);

void init(int node, int start, int end) {
	if (start == end) segment_tree[node] = start;
	else {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		segment_tree[node] = segment_tree[node * 2] + segment_tree[node * 2 + 1];
		long long m1 = segment_tree[node * 2];
		long long m2 = segment_tree[node * 2 + 1];
		if (input[m1] > input[m2]) { segment_tree[node] = m2; }
		else { segment_tree[node] = m1; }
	}
}

void update(int node, int start, int end, int index, int value) {
	if (index < start || end < index)
		return;
	if (start == end) {
		segment_tree[node] = index;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, value);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	long long m1 = segment_tree[node * 2];
	long long m2 = segment_tree[node * 2 + 1];
	if (input[m1] > input[m2]) { segment_tree[node] = m2; }
	else { segment_tree[node] = m1; }
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	input = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	init(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int order;
		cin >> order;
		if (order == 2) {
			cout << segment_tree[1] << "\n";
		}
		else {
			int pos, value;
			cin >> pos >> value;
			input[pos] = value;
			update(1, 1, n, pos, value);
		}
	}

	return 0;
}