#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int>> graph[20001];
int dist[20001];	// 거리 저장
int INF = 1000000000;

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (dist[cur] < distance) continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDistance = distance + graph[cur][i].second;

			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int V = 0, E = 0, S = 0;
	cin >> V >> E >> S;

	for (int i = 1; i <= E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	dijkstra(S);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";

		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}