#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int input[102][102];
int board[102][102];
bool vis[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N;
int cnt;
queue<pair<int, int>> Q;
vector<int> ans;
void BFS(int i, int j) {
	Q.push({ i,j });
	vis[i][j] = true;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			//if (board[nx][ny] == 0 || vis[nx][ny]) continue;
			if (board[nx][ny] && !vis[nx][ny]) {
				vis[nx][ny] = true;
				Q.push({ nx,ny });
			}
		}
	}
}
void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
			vis[i][j] = false;
		}
	}

	cnt = 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int maxHeight = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
			if (input[i][j] > maxHeight)
				maxHeight = input[i][j];
		}
	}
	for (int h = 1; h <= maxHeight; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (input[i][j] < h) {
					board[i][j] = 0;
				}
				else {
					board[i][j] = 1;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//if (board[i][j] == 0 || vis[i][j]) continue;
				if (board[i][j] && !vis[i][j]) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		ans.push_back(cnt);

		reset();
	}
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1];
}