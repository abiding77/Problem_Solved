#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std;

int R, C;
string board[1002];   // 지도 보드
int dist1[1002][1002]; // 지훈이
int dist2[1002][1002]; // 불
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) { // 메모리 초기화 먼저
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}
	
	queue<pair<int, int>> Q1; // 불 BFS 큐
	queue<pair<int, int>> Q2; // 지훈이 BFS 큐
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'F') { 
				Q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!Q1.empty()) { // 불 전파 시간
		pair<int, int> cur = Q1.front(); Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			Q1.push({ nx,ny });
		}
	}
	while (!Q2.empty()) { // 지훈이 거리를 두번째로 돌려야 비교 가능
		pair<int, int> cur = Q2.front(); Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) { // 범위를 벗어난것이 출력일듯 종료해야함
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}
			if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) continue;
			// 불 전파 시간 벗어나면 튀어야됨
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE"; // 여까지 오면 불가능
}