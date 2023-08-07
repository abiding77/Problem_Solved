#include <iostream>

using namespace std;

int R, C, T;
int totalDust;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int up_row, down_row;
int board[51][51];
int addArr[51][51];
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
				else
					down_row = i;
			}
			else
				totalDust += board[i][j];
		}
	}
}

void spread() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int val = board[i][j] / 5;
			int cnt = 0;
			if (board[i][j] == 0 || board[i][j] == -1) continue;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (board[nr][nc] == -1) continue;
				if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
				addArr[nr][nc] += val;
				cnt++;
			}
			addArr[i][j] -= (val * cnt);
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

	// 위쪽 순회
	// 1. 왼쪽줄
	for (int i = up_row - 1; i > 0; i--) 
		board[i][0] = board[i-1][0];
	// 2. 윗쪽줄
	for (int i = 0; i < C - 1; i++)
		board[0][i] = board[0][i+1];
	// 3. 오른쪽줄 // [0][0] = [1][0] , [1][0] = [2][0]
	for (int i = 1; i <= up_row; i++)
		board[i-1][C-1] = board[i][C-1];
	// 4. 아래줄 // 7 = 6 6 = 5 5 = 4 4 = 3 3 = 2 2 = 1
	for (int i = C - 1; i > 1; i--)
		board[up_row][i] = board[up_row][i - 1];
	board[up_row][1] = 0;

	// 아래쪽 순회
	// 1. 왼쪽줄
	for (int i = down_row + 1; i < R - 1; i++)
		board[i][0] = board[i+1][0];
	// 2. 아래쪽줄
	for (int i = 0; i < C - 1; i++)
		board[R - 1][i] = board[R - 1][i+1];
	// 3. 오른쪽줄
	for (int i = R - 1; i >= down_row+1; i--)  // 6 = 5 ,5 = 4 , 4=3
		board[i][C - 1] = board[i - 1][C - 1];
	
	// 4. 윗족줄
	for (int i = C - 1; i >= 2; i--) 
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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> T;
	input();
	solve();
	return 0;
}