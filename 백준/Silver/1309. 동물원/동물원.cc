#include <iostream>

using namespace std;

int dp[100002] = { 1,3 };
int N;
int mod = 9901;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % mod;
	}
	cout << dp[N];
}