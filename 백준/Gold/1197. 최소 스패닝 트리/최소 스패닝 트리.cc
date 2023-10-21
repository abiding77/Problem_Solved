#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int V, E;
int dist[10001];
vector<pair<int, int>> map[10001];
long long prim() {
	long long cnt = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ; // first 가중치 second 정점
	PQ.push({ 0,1 });

	while (!PQ.empty()) {
		int cost = PQ.top().first;
		int vertex = PQ.top().second;
		PQ.pop();
		if (dist[vertex]) continue;
		dist[vertex] = 1;
		cnt += cost;

		for (int i = 0; i < map[vertex].size(); i++) {
			if (!dist[map[vertex][i].second]) {
				PQ.push(map[vertex][i]);
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ c,b });
		map[b].push_back({ c,a });
	}
	long long result = prim();
	cout << result;
	return 0;
}