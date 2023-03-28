#include <iostream>

using namespace std;

long long dp[10002];
long long arr[102];
int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1; // 동전 선택 X
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << '\n';
	return 0;
}