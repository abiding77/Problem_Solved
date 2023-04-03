#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N, M; // 맵 크기, 이동 수
int basket[52][52]; // 바구니
int di, si; // 이동방향 , 이동거리
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 
int dx[9] = { 99,-1, -1,0,1,1,1,0,-1 };
int dy[9] = { 99,0,-1,-1,-1,0,1,1,1 };
queue<pair<int, int>> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> basket[i][j];
		}
	}
	// 초기 비바라기 시전
	q.push({ N,1 });
	q.push({ N,2 });
	q.push({ N-1,1 });
	q.push({ N-1,2 });
	while (M--) {
		bool visited[51][51] = { false }; // 구름 체크
		vector<pair<int, int>> v; // 구름 좌표
		cin >> di >> si;
		int ssize = q.size();
		for (int i = 0; i < ssize; i++) {
			// 좌표 꺼내고
			int r = q.front().first;
			int c = q.front().second;
			q.pop(); // 구름 전부 없애
			for (int j = 0; j < si; j++) {
				r += dy[di];
				c += dx[di];

				if (r < 1) {
					r = N;
				}
				if (r > N) {
					r = 1;
				}
				if (c < 1) {
					c = N;
				}
				if (c > N) {
					c = 1;
				}
			}
			basket[r][c]++; // 구름에서 비내려서 1 증가
			visited[r][c] = true; // 구름 있는 칸 체크
			v.push_back({ r,c }); // 구름 좌표 재저장
		}
		// 물이 증가 한 칸에 물복사버그 시전 -> 대각선 방향으로 거리가 1인 칸 바구니 수만큼 물의 양이 증가 (범위벗어나는곳 X)
		for (int i = 0; i < ssize; i++) {
			int r = v[i].first;
			int c = v[i].second;
			// 대걱산 2,4,6,8 방향
			for (int j = 2; j <= 9; j += 2) {
				int nr = r + dy[j];
				int nc = c + dx[j];

				// 범위 안벗어나고 대각선 방향 물이 있는 경우
				if (nr <= N && nc <= N && nr >= 1 && nc >= 1 && basket[nr][nc]) {
					basket[r][c]++;
				}
			}
		}
		// 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름 만들고 물양 -2
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (basket[i][j] >= 2 && !visited[i][j]) {
					q.push({ i,j });
					basket[i][j] -= 2;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (basket[i][j] > 0) {
				cnt += basket[i][j];
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}