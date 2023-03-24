#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int board1[10][10]; // 첫 지도
int board2[10][10]; // 사각지대
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;
vector<pair<int, int>> cctv;

bool OOB(int a, int b) { // 범위 체크
	return a < 0 || a >= N || b < 0 || b >= M;
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
			if (board1[i][j] == 0) ans++;
		}
	}
}
void upd(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return;
		if (board2[x][y] != 0) continue;
		board2[x][y] = 7;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4;
			brute /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			if (board1[x][y] == 1) { // 1번 CCTV
				upd(x, y, dir);
			}
			else if (board1[x][y] == 2) { // 2번 CCTV
				upd(x, y, dir);
				upd(x, y, dir + 2);
			}
			else if (board1[x][y] == 3) { // 3번 CCTV
				upd(x, y, dir);
				upd(x, y, dir + 1);
			}
			else if (board1[x][y] == 4) { // 4번 CCTV
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
			}
			else { // 5번 CCTV
				upd(x, y, dir);
				upd(x, y, dir + 1);
				upd(x, y, dir + 2);
				upd(x, y, dir + 3);
			}
		}
		int val = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				val += (board2[i][j] == 0);
			}
		}
		ans = min(ans, val);
	}
	cout << ans;
}