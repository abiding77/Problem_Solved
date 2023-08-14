// --> next_permutation Version
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int N, M;
//int arr[10];
//int pre[10];
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		arr[i] = i + 1;
//	}
//	sort(arr, arr + N);
//	do {
//		bool flag = false;
//		for (int i = 0; i < M; i++) {
//			if (pre[i] != arr[i]) {
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) continue;
//		for (int i = 0; i < M; i++) {
//			cout << arr[i] << " ";
//			pre[i] = arr[i];
//		}
//		cout << '\n';
//	} while (next_permutation(arr, arr + N));
//}

// BackTraking Version
#include <iostream>

using namespace std;
int N, M;
int arr[10];
bool visited[10];
void DFS(int num) {
	if (num == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			arr[num] = i;
			visited[i] = true;
			DFS(num + 1);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	DFS(0);
}