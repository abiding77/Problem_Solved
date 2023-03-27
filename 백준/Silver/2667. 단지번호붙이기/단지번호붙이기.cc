#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int board[26][26];
int N;
bool vis[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
vector<int> home;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int, int>> Q;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			board[i][j] = tmp[j] - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;
			cnt++;
			Q.push({ i,j });
			vis[i][j] = true;
			int mx = 0;
			while (!Q.empty()) {
				pair<int, int> cur = Q.front(); Q.pop();
				mx++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;
					Q.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}
			home.push_back(mx);
		}
	}
	sort(home.begin(), home.end());
	cout << cnt << '\n';
	for (int i = 0; i < home.size(); i++) {
		cout << home[i] << '\n';
	}
}