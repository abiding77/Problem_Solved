#include <iostream>
#include <vector>


using namespace std;
int N, K;
int answer;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> coin;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		coin.push_back(num);
	}
	int idx = coin.size()-1;
	while (K > 0) {
		if (K >= coin[idx]) {
			answer += K / coin[idx];
			K %= coin[idx];
		}
		else idx--;
	}
	cout << answer << '\n';
}