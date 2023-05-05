#include <iostream>

using namespace std;

int coin[6] = { 500,100,50,10,5,1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int money;
	int answer = 0;
	cin >> money;
	money = 1000 - money;
	int idx = 0;
	while (money > 0) {
		if (money >= coin[idx]) {
			money -= coin[idx];
			answer++;
		}
		else {
			idx++;
		}
	}
	cout << answer;
	return 0;
}