#include <iostream>

using namespace std;

int e, s, m;
int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i = 0, j = 0, k = 0;
	cin >> e >> s >> m;
	while (1) {
		i++, j++, k++, cnt++;
		if (i == e && j == s && k == m) {
			cout << cnt << '\n';
			return 0;
		}
		if (i == 15) i = 0;
		if (j == 28) j = 0;
		if (k == 19) k = 0;
	}
}