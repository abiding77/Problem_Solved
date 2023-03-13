#include <iostream>
#include <algorithm>

using namespace std;

int T;
int table[2][100002];
int dp[2][100002];
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> table[i][j];
			}
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = table[0][1];
		dp[1][1] = table[1][1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + table[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + table[1][i];
		}
		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
}