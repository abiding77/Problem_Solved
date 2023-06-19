/*
add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int M;
	cin >> M;
	int arr[20] = { 0 };
	while (M--) {
		string s;
		int n;
		cin >> s;
		if (s == "add") {
			cin >> n;
			if (arr[n - 1] == 1) continue;
			else arr[n - 1] = 1;
		}
		if (s == "remove") {
			cin >> n;
			if (arr[n - 1] == 0) continue;
			else arr[n - 1] = 0;
		}
		if (s == "check") {
			cin >> n;
			if (arr[n - 1] == 1) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (s == "toggle") {
			cin >> n;
			if (arr[n - 1] == 1) arr[n - 1] = 0;
			else arr[n - 1] = 1;
		}
		if (s == "all") {
			for (int i = 0; i < 20; i++) {
				arr[i] = 1;
			}
		}
		if (s == "empty") {
			memset(arr, 0, sizeof(arr));
		}
	}
}