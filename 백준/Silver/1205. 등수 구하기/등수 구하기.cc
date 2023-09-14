#include <iostream>
#include <vector>
using namespace std;

int scoreList[51];
int N, newScore, P;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> newScore >> P;
	for (int i = 0; i < N; i++) {
		cin >> scoreList[i];
	}
	int ans = 1;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (scoreList[i] > newScore) ans++;
		else if (scoreList[i] == newScore) ans = ans;
		else break;
		cnt++;
	}
	if (cnt == P) ans = -1;
	if (N == 0) ans = 1;

	cout << ans;
}