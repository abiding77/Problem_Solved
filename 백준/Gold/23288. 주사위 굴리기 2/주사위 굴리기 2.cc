#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, M, K;
int map[25][25];
bool visit[25][25];
// index 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면
int dice[7] = { 0,1,2,3,4,5,6 };
int point;
// 동서남북
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int reverseDir(int d) {
	switch (d) {
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	}
}
void getScore(int a, int b) {
	memset(visit, false, sizeof(visit));
	int num = map[a][b];
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visit[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dr[i];
			int ny = y + dc[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (map[nx][ny] == num && !visit[nx][ny]) {
					visit[nx][ny] = true;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
	}
	point += (num * cnt);
}
void updateDiceState(int d) {
	int d1 = dice[1];
	int d2 = dice[2];
	int d3 = dice[3];
	int d4 = dice[4];
	int d5 = dice[5];
	int d6 = dice[6];
	switch (d) {
	case 0:
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
		break;
	case 1:
		dice[1] = d3;
		dice[3] = d6;
		dice[6] = d4;
		dice[4] = d1;
		break;
	case 2:
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
		dice[5] = d1;
		break;
	case 3:
		dice[1] = d5;
		dice[5] = d6;
		dice[6] = d2;
		dice[2] = d1;
		break;
	}
}
int changeDir(int d, int ret) {
	if (ret > 0) {
		switch (d) {
		case 0:
			return 2;
		case 1:
			return 3;
		case 2:
			return 1;
		case 3:
			return 0;
		}
	}
	else if (ret < 0) {
		switch (d) {
		case 0:
			return 3;
		case 1:
			return 2;
		case 2:
			return 0;
		case 3:
			return 1;
		}
	}
	return d;
}
void moveDice() {
	int x = 0;
	int y = 0;
	int d = 0;
	for (int i = 0; i < K; i++) {
		int nx = x + dr[d];
		int ny = y + dc[d];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			d = reverseDir(d);
			nx = x + dr[d];
			ny = y + dc[d];
		}
		getScore(nx, ny);
		updateDiceState(d);
		d = changeDir(d, dice[6] - map[nx][ny]);
		x = nx;
		y = ny;
	}
	cout << point << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	moveDice();
	return 0;
}