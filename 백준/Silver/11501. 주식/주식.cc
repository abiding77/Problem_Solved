#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		vector<int> stock;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			stock.push_back(a);
		}
		long long result = 0;
		int M = stock.back();
		for (int i = stock.size() - 2; i >= 0; i--) {
			if (stock[i] > M) {
				M = stock[i];
			}
			else {
				result += M - stock[i];
			}
		}
		cout << result << "\n";
	}
}