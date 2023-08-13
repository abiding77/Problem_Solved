#include <iostream>

#define MAX 9

using namespace std;

int arr[MAX];
bool visited[MAX];
int N, M;
void DFS(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++) {
		visited[i] = true;
		arr[cnt] = i;
		DFS(i, cnt + 1);
		visited[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	DFS(1, 0);
}