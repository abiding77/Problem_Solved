#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

int dx[2] = { -1,0 };
int dy[2] = { 0,1 };
int N, M;
vector<vector<int>> BFS(int x, int y, int flag) {
	vector<vector<int>> tmp(N, vector<int>(M,INT32_MIN));
	tmp[x][y] = graph[x][y];
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	while (!Q.empty()) {
		int curX = Q.front().first;
		int curY = Q.front().second;
		Q.pop();
		for (int i = 0; i < 2; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i] * flag;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (tmp[nx][ny] < tmp[curX][curY] + graph[nx][ny]) {
				tmp[nx][ny] = tmp[curX][curY] + graph[nx][ny];
				Q.push({ nx,ny });
			}
		}
	}
	return tmp;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	graph.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	vector<vector<int>> upper = BFS(N-1,0,1);
	vector<vector<int>> lower = BFS(N - 1, M - 1, -1);
	int ans = INT32_MIN;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (upper[i][j] + lower[i][j] > ans) {
				ans = upper[i][j] + lower[i][j];
			}
		}
	}
	cout << ans;
}