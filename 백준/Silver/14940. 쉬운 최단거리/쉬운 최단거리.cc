#include <iostream>
#include <queue>
using namespace std;

int graph[1002][1002];
int dist[1002][1002];
bool visited[1002][1002];
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int firstX, firstY;
void BFS(int x, int y) {
	queue<pair<int, int>> Q;
	dist[x][y] = 0;
	visited[x][y] = true;
	Q.push({ x,y });
	while (!Q.empty()) {
		int curX = Q.front().first;
		int curY = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (graph[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;
			dist[nx][ny] = dist[curX][curY] + 1;
			visited[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				firstX = i;
				firstY = j;
			}
		}
	}
	BFS(firstX, firstY);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 1 && dist[i][j] == 0) cout << -1 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}