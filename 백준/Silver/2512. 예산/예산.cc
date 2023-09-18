#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
int arr[10002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> M;
	sort(arr, arr + N);
	// 110 120 140 150 , 485

	int left = 0;
	int right = arr[N - 1];

	int sum, ans;
	while (left <= right) {
		sum = 0;
		int mid = (left + right) / 2; 
		for (int i = 0; i < N; i++) {
			sum += min(arr[i], mid);
		}
		if (M >= sum) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
}