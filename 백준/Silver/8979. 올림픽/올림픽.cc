#include <iostream>

using namespace std;

int gold[1002];
int silver[1002];
int bronze[1002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int idx;
		cin >> idx;
		cin >> gold[idx] >> silver[idx] >> bronze[idx];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (gold[i] > gold[K]) {
			ans++;
		}
		else if (gold[i] == gold[K]) {
			if (silver[i] > silver[K]) {
				ans++;
			}
			else if (silver[i] == silver[K]) {
				if (bronze[i] > bronze[K]) {
					ans++;
				}
			}
		}
	}
	cout << ans + 1;
}