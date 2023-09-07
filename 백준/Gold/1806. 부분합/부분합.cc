#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, S;
	int minNum = INT32_MAX;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int tot = arr[0];
	int ed = 0;
	for (int st = 0; st < N; st++) {
		while (ed < N && tot < S) {
			ed++;
			if (ed != N) tot += arr[ed];
		}
		if (ed == N) break;
		minNum = min(minNum, ed - st + 1);
		tot -= arr[st];
	}
	if (minNum == INT32_MAX) minNum = 0;
	cout << minNum;
}