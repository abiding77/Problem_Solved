#include <iostream>

using namespace std;

int X, Y;
// 유클리드 호제법 최대공약수
int GCD(int a, int b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> X >> Y;
	cout << GCD(X, Y) << '\n';
	cout << (X * Y) / GCD(X, Y) << '\n';
}