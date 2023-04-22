#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int V, E;
int K;
vector<pair<int, int>> adj[20005];
int dist[20005];
const int INF = 1e9 + 10;
void BFS(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ dist[start],start });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		// 거리,정점
		if (dist[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
			dist[nxt.second] = dist[cur.second] + nxt.first;
			pq.push({ dist[nxt.second],nxt.second });
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	fill(dist, dist + V + 1, INF);
	cin >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}
	BFS(K);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}