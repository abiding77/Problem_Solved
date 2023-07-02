#include <iostream>
#include <math.h>

using namespace std;

int N, r, c;
int answer;
void Z(int x, int y, int size) {
	if (y == r && x == c) {
		cout << answer;
		return;
	}
	else if (r < y + size && c < x + size && c >= x && r >= y) { // 사분면 내부인 경우
		Z(x, y, size / 2);
		Z(x + size / 2, y, size / 2);
		Z(x, y + size / 2, size / 2);
		Z(x + size / 2, y + size / 2, size / 2);
	}
	else answer += size * size;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> r >> c;
	Z(0, 0, pow(2,N));
}