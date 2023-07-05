#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;


vector<int> friends[101];
int dist[101][101];

void BFS(int start) {
	queue<int> q;
	bool vis[101] = { false, };
	q.push(start);
	vis[start] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = 0; i < friends[cur].size(); i++) {
			int nxt = friends[cur][i];
			if (!vis[nxt]) {
				vis[nxt] = true;
				q.push(nxt);
				dist[nxt][start] = dist[cur][start] + 1;
				dist[start][nxt] = dist[start][cur] + 1;
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
	int result = 0;
	int min = 2100000000;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	memset(dist, 0, sizeof(dist));
	for (int i = 1; i <= N; i++) BFS(i);

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += dist[i][j];
		}
		if (min > sum) {
			min = sum;
			result = i;
		}
	}
	cout << result << '\n';
}