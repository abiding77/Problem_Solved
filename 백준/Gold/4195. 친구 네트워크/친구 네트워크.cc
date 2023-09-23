#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int sizes[200002];
int links[200002];

int finds(int x) {
	if (links[x] == x) return x;
	return links[x] = finds(links[x]);
}
void unite(int a, int b) {
	a = finds(a);
	b = finds(b);

	if (a != b) {
		if (sizes[a] < sizes[b]) swap(a, b);
		sizes[a] += sizes[b];
		links[b] = a;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int F;
		cin >> F;
		for (int i = 0; i < 200002; i++) {
			sizes[i] = 1;
			links[i] = i;
		}
		map<string, int> map;
		int nodeNum = 1;
		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
			if (map.count(a) == 0) map[a] = nodeNum++;
			if (map.count(b) == 0) map[b] = nodeNum++;
			unite(map[a], map[b]);
			int p1 = finds(map[a]);
			int p2 = finds(map[b]);
			cout << max(sizes[p1], sizes[p2]) << '\n';
		}
	}
}