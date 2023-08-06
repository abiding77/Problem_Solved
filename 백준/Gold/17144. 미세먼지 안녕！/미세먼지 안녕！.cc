#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int board[51][51];
int addArr[51][51];
int R, C, T;
int up_row, down_row;
int totalDust;
/*
1. 미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
확산되는 양은 Ar,c/5이고 소수점은 버린다.
(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
2. 공기청정기가 작동한다.
공기청정기에서는 바람이 나온다.
위쪽 공기청정기의 바람은 반시계방향으로 순환하고, 아래쪽 공기청정기의 바람은 시계방향으로 순환한다.
바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
공기청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기청정기로 들어간 미세먼지는 모두 정화된다.
*/
void input() {
	bool flag = false;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				if (!flag) {
					up_row = i;
					flag = true;
				}
				else {
					down_row = i;
				}
			}
			else {
				totalDust += board[i][j];
			}
		}
	}
}
void spread() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int cnt = 0;
			int val = board[i][j] / 5;
			if (board[i][j] == 0 || board[i][j] == -1) continue;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				if (board[nr][nc] == -1) continue;
				addArr[nr][nc] += val;
				cnt++;
			}
			addArr[i][j] -= (cnt * val);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			board[i][j] += addArr[i][j];
			addArr[i][j] = 0;
		}
	}
}

void airCleaner() {
	totalDust -= board[up_row - 1][0];
	totalDust -= board[down_row + 1][0];

	// 위 공기 순환 ( 반시계)
	// 1. 왼쪽줄
	for (int i = up_row - 1; i > 0; i--)
		board[i][0] = board[i - 1][0];
	// 2. 윗줄
	for (int i = 0; i < C - 1; i++)
		board[0][i] = board[0][i + 1];
	// 3. 오른쪽줄
	for (int i = 1; i <= up_row; i++)
		board[i - 1][C - 1] = board[i][C - 1];
	// 4. 아랫줄
	for (int i = C - 1; i > 1; i--)
		board[up_row][i] = board[up_row][i - 1];
	board[up_row][1] = 0;

	// 아래 공기 순환 (시계)
	// 1. 왼쪽줄 [4][0] = [5][0]   , [5][0] = [6][0];
	for (int i = down_row + 1; i < R - 1; i++)
		board[i][0] = board[i + 1][0];
	// 2. 아랫줄
	for (int i = 0; i < C - 1; i++)
		board[R - 1][i] = board[R - 1][i + 1];
	// 3. 오른쪽줄
	for (int i = R - 1; i >= down_row; i--)
		board[i][C - 1] = board[i - 1][C - 1];
	// 4. 윗줄
	for (int i = C - 1; i > 1; i--)
		board[down_row][i] = board[down_row][i - 1];
	board[down_row][1] = 0;

}
void solve() {
	while (T--) {
		spread();
		airCleaner();
	}
	cout << totalDust << '\n';
}
//void print() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cout << board[i][j] << " ";
//		}
//		cout << '\n';
//	}
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> T;
	input();
	solve();

	return 0;
}