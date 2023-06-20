#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
/*
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
*/
vector<int> graph[1001];
bool visited[1001];
queue<int> Q;

void BFS(int start) {
	Q.push(start);
	visited[start] = true;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			if (visited[graph[cur][i]] == false) {
				visited[graph[cur][i]] = true;
				Q.push(graph[cur][i]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	int answer = 0;
	memset(graph, 0, sizeof(graph));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			BFS(i);
			answer++;
		}
	}
	cout << answer << '\n';
}