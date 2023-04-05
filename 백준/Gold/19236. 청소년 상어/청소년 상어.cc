#include <iostream>
#include <utility>

using namespace std;

struct Fish {
	int num;
	int x;
	int y;
	int dir;
	bool live;
};
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,-1,-1,-1,0,1,1,1 };
int board[4][4];
Fish fishArr[17];
int ret;

void DFS(int board[][4], Fish fishArr[], int shark_r, int shark_c, int s) {
	int copy_board[4][4];
	Fish copy_fishArr[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy_board[i][j] = board[i][j];
		}
	}
	for (int i = 0; i < 17; i++) {
		copy_fishArr[i] = fishArr[i];
	}
	int fishNum = copy_board[shark_r][shark_c];
	int sharkDir = copy_fishArr[fishNum].dir; // 잡아먹은 물고기 방향으로 바뀜
	copy_fishArr[fishNum].live = false;
	copy_board[shark_r][shark_c] = -1; // 물고기 없어짐
	s += fishNum;
	if (ret < s) ret = s;

	// 물고기 이동
	for (int i = 1; i <= 16; i++) {
		if (copy_fishArr[i].live == false) continue;
		// 현재 물고기
		int cr = copy_fishArr[i].x;
		int cc = copy_fishArr[i].y;
		int cd = copy_fishArr[i].dir;
		// 바꿀 타겟
		int nr = cr + dr[cd];
		int nc = cc + dc[cd];
		int nd = cd;

		// 타겟이 범위 넘어가거나 상어면 회전
		while (nr >= 4 || nc >= 4 || nc < 0 || nr < 0 || (nr == shark_r && nc == shark_c)) {
			nd = (nd + 1) % 8;
			nr = cr + dr[nd];
			nc = cc + dc[nd];
		}
		// 1. 타겟 칸이 물고기면
		if (copy_board[nr][nc] != -1) {
			int targetFishNum = copy_board[nr][nc];
			// 타겟 물고기 위치 갱신
			copy_fishArr[targetFishNum].x = cr;
			copy_fishArr[targetFishNum].y = cc;
			// 현재 물고기 위치 갱신
			copy_fishArr[i].x = nr;
			copy_fishArr[i].y = nc;
			copy_fishArr[i].dir = nd;
			// 이차원 배열 번호 swap
			copy_board[nr][nc] = i;
			copy_board[cr][cc] = targetFishNum;
		}
		// 2. 타겟 칸이 빈칸이면
		else {
			copy_fishArr[i].x = nr;
			copy_fishArr[i].y = nc;
			copy_fishArr[i].dir = nd;

			copy_board[nr][nc] = i;
			copy_board[cr][cc] = -1; // 원래 물고기 있던 칸은 물고기 없어짐.
		}
	}

	//상어 이동
	for (int step = 1; step <= 3; step++) {
		int nr = shark_r + dr[sharkDir] * step;
		int nc = shark_c + dc[sharkDir] * step;
		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break;
		if (copy_board[nr][nc] != -1) {
			DFS(copy_board, copy_fishArr, nr, nc, s);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int num, dir;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num >> dir;
			Fish fish = Fish({ num,i,j,dir - 1,true });
			board[i][j] = num;
			fishArr[num] = fish;
		}
	}
	ret = 0;
	DFS(board, fishArr, 0, 0, 0);
	cout << ret;
	return 0;
}
