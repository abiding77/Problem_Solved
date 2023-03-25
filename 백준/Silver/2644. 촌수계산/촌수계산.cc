#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[102];
bool vis[102];
int S,E;
int ans = 0;
void DFS(int now,int end,int num) {
	vis[now] = true;
	if (now == end)
		ans = num;
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (!vis[next]) {
			DFS(next, end, num + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S >> E >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(S,E,0);
	if (ans == 0) {
		cout << -1;
	}
	else
		cout << ans;
}