#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T[16];
int P[16];
int dp[16];
int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	int next;
	for (int i = N; i > 0; i--) {
		next = i + T[i]; // 초기 next = 9
		if (next > N + 1) {
			dp[i] = dp[i + 1]; 
		}
		else { 
			dp[i] = max(dp[i + 1], dp[next] + P[i]);
		}
	}
	cout << dp[1] << '\n';
	return 0;
}