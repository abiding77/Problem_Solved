#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[102];
bool vis[102];
int N,M;
int ans = 0;
void DFS(int v) {
	vis[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int cur = graph[v][i];
		if (!vis[cur]) {
			DFS(cur);
			ans++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);
	cout << ans;
}