#include <iostream>

using namespace std;
int light[4001];

void lightCtrl(int ctrl, int x, int r) {
	if (ctrl == 1) {
		light[x] = r;
	}
	else if (ctrl == 2) {
		for (int i = x; i <= r; i++) {
			light[i] = !light[i];
		}
	}
	else if (ctrl == 3) {
		for (int i = x; i <= r; i++) {
			light[i] = 0;
		}
	}
	else {
		for (int i = x; i <= r; i++) {
			light[i] = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		light[i] = a;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lightCtrl(a, b, c);
	}

	for (int i = 1; i <= N; i++) {
		cout << light[i] << " ";
	}
}