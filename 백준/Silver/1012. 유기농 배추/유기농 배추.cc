#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int arr[51][51];
bool vis[51][51];
int M, N, K;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;

void BFS(int x, int y) {
	Q.push({ x,y });
	vis[x][y] = true;
	while (!Q.empty()) {
		int curX = Q.front().first;
		int curY = Q.front().second;
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if (nx >= M || nx < 0 || ny >= N || ny < 0) continue;
			if (arr[nx][ny] == 1 && !vis[nx][ny]) {
				Q.push({ nx,ny });
				vis[nx][ny] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> M >> N >> K;
		memset(arr, 0, sizeof(arr));
		memset(vis, false, sizeof(vis));
		int num = 0;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				arr[i][j] = 0;

		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1 && vis[i][j] == false) {
					BFS(i, j);
					num++;
				}
			}
		}
		cout << num << '\n';
	}
}