#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<>> PQ;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			if (PQ.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << PQ.top() << '\n';
				PQ.pop();
			}
		}
		else
			PQ.push(a);
	}
}