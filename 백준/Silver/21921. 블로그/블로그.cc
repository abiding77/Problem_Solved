#include <iostream>
#include <vector>

using namespace std;

int sumList[250002];
int answer_V, answer_D;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, X;
	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		sumList[i] = sumList[i - 1] + a;
	}
	for (int i = X; i <= N; i++) { // i= 2 ~ 5
		int tmp = sumList[i] - sumList[i - X]; // sumList[2] - sumList[0]
		if (tmp > answer_V) {
			answer_V = tmp;
			answer_D = 1;
		}
		else if (answer_V == tmp) answer_D++;
	}
	if (answer_V > 0) cout << answer_V << '\n' << answer_D;
	else cout << "SAD\n";
}