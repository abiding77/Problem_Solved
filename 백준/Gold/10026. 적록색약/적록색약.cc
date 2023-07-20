#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int N;
char board[101][101];
bool visited[101][101];
int ans1, ans2;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS(int a, int b) {
	visited[a][b] = true;
	queue<pair<int, int>> Q;
	Q.push({ a,b });
	while (!Q.empty()) {
		int curX = Q.front().first;
		int curY = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (visited[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx > N || ny > N) continue;
			if (board[curX][curY] == board[nx][ny]) {
				visited[nx][ny] = true;
				Q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				BFS(i, j);
				ans1++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'R') board[i][j] = 'G';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == false) {
				BFS(i, j);
				ans2++;
			}
		}
	}
	cout << ans1 << " " << ans2;
}