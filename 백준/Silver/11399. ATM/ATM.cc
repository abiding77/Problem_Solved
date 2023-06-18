#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int moneyTime[1001];
int main() {
	int N;
	int totalTime = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> moneyTime[i];
	}

	sort(moneyTime, moneyTime+N);
	for (int i = 0; i < N; i++) {
		totalTime += moneyTime[i] * (N-i);
	}
	cout << totalTime;
}