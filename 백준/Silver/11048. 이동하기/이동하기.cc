#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int board[1005][1005];
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int answer = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	dp[1][1] = board[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			answer = max({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] });
			dp[i][j] = answer + board[i][j];
		}
	}
	cout << dp[N][M] << '\n';
}