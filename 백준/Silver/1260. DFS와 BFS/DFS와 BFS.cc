#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, V;
vector<int> graph[1002];
bool dvis[1002];
bool bvis[1002];
queue<int> Q;

void DFS(int v) {
	dvis[v] = true;
	cout << v << " ";
	for (int i = 0; i < graph[v].size(); i++) {
		int cur = graph[v][i];
		if (!dvis[cur])
			DFS(cur);
	}
}
void BFS(int v) {
	Q.push(v);
	bvis[v] = true;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!bvis[next]) {
				bvis[next] = true;
				Q.push(next);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());
	DFS(V);
	cout << '\n';
	BFS(V);
}