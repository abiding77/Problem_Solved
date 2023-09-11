#include <iostream>
#include <string>
using namespace std;

char cookie[1002][1002];
int N;
int headX, headY;
int leftLen, rightLen, downLen, leftLeg, rightLeg;
int idx;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cookie[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cookie[i][j] == '*') {
				headX = i;
				headY = j;
				break;
			}
		}
		if (headX != 0 || headY != 0) break;
	}
	for (int i = headY-1; i >= 1; i--) {
		if (cookie[headX + 1][i] == '*') leftLen++; // 왼쪽팔
	}
	for (int i = headY + 1; i <= N; i++) {
		if (cookie[headX + 1][i] == '*') rightLen++; // 오른쪽팔
	}
	for (int i = headX + 2; i <= N; i++) {
		if (cookie[i][headY] == '*') {
			downLen++; // 허리
		}
	}
	for (int i = N; i >= 1; i--) {
		if (cookie[i][headY - 1] == '*') leftLeg++; // 왼쪽 다리
	}

	for (int i = N; i >= 1; i--) {
		if (cookie[i][headY + 1] == '*') rightLeg++;
	}
	cout << headX+1 << " " << headY << '\n';
	cout << leftLen << " " << rightLen << " " << downLen << " " << --leftLeg << " " << --rightLeg;
}