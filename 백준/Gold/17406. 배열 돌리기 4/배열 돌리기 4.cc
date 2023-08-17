#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rotation {
	int rr, cc, ss;
};
vector<rotation> arr;
int board[51][51];
int tmpBoard[51][51];
int N, M, K;
int r, c, s;
bool check[6]; // 회전연산 표시
int order[6]; // 회전연산 순서
int answer = 987654321;
void Rolling(int r, int c, int s) {
	for (int d = 1; d <= s; d++) {
		int tmp = tmpBoard[r - d][c - d];
		// 왼쪽줄   (3,4,2)   i=3; i<= 4; i++
		// [2][3] = [3][3] , [3][3] = [4][3];
		// i=2; i<=5; i++
		// [1][2] = [2][2] , [2][2] = [3][2] , [3][2] = [4][2] , [4][2] = [5][2];
		for (int i = r - d + 1; i <= r + d; i++) {
			tmpBoard[i - 1][c - d] = tmpBoard[i][c - d];
		}
		//아래쪽줄
		for (int i = c - d + 1; i <= c + d; i++) {
			tmpBoard[r + d][i - 1] = tmpBoard[r + d][i];
		}
		//오른쪽변
		for (int i = r + d - 1; i >= r - d; i--) {
			tmpBoard[i + 1][c + d] = tmpBoard[i][c + d];
		}
		//위쪽변
		for (int i = c + d - 1; i > c - d; i--) {
			tmpBoard[r - d][i + 1] = tmpBoard[r - d][i];
		}
		tmpBoard[r - d][c - d + 1] = tmp;
	}
}
void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		arr.push_back({ r,c,s });
	}
}

void simulation() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmpBoard[i][j] = board[i][j];
		}
	}

	// 회전연산 수행 - 정해진 순서
	for (int i = 0; i < K; i++) {
		int od = order[i];
		int curR = arr[od].rr;
		int curC = arr[od].cc;
		int curS = arr[od].ss;
		Rolling(curR, curC, curS);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			res += tmpBoard[i][j];
		}
		answer = min(answer, res);
		res = 0;
	}
}
void DFS(int cnt) {
	if (cnt == K) {
		simulation();
		return;
	}
	for (int i = 0; i < K; i++) {
		if (check[i]) continue;
		check[i] = true;
		order[cnt] = i;
		DFS(cnt + 1);
		check[i] = false;
	}
}
//void print() {
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cout << tmpBoard[i][j] << " ";
//		}
//		cout << '\n';
//	}
//	cout << " ---------------------- " << '\n';
//	for (int i = 0; i < arr.size(); i++) {
//		cout << arr[i].rr << " " << arr[i].cc << " " << arr[i].ss << '\n';
//	}
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	DFS(0);
	//print();
	cout << answer << '\n';
	return 0;
	//print();
}