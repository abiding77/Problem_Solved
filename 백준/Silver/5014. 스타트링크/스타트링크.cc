#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int vis[1000002];
int F, S, G, U, D;
queue<pair<int, int>> Q;
void BFS() {
	Q.push({ S,0 });
	vis[S] = 1;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		if (cur.first == G) {
			cout << cur.second;
			return;
		}
		int floor_up = cur.first + U;
		int floor_down = cur.first - D;
		if (floor_up <= F && vis[floor_up] == 0) {
			vis[floor_up] = 1;
			Q.push({ floor_up,cur.second + 1 });
		}
		if (floor_down >= 1 && vis[floor_down] == 0) {
			vis[floor_down] = 1;
			Q.push({ floor_down,cur.second + 1 });
		}
	}
	cout << "use the stairs";
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	BFS();
	return 0;
}