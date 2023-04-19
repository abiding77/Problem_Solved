#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	int N;
	pair<int, int> employee[100001];
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			employee[i].first = a;
			employee[i].second = b;
		}
		sort(employee,employee+N);
		int result = 1;
		int rankNumber = employee[0].second;
		for (int i = 1; i < N; i++) {
			if (employee[i].second < rankNumber) {
				result++;
				rankNumber = employee[i].second;
			}
		}
		cout << result << '\n';
	}
}