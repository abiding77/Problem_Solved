#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, int> word;

bool cmp(pair<string,int> a, pair<string,int> b) {
	if (a.second == b.second) {
		if (a.first.length() == b.first.length()) return a.first < b.first;
		return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s.length() >= M) word[s]++;
	}
	vector<pair<string, int>> v(word.begin(), word.end());
	sort(v.begin(), v.end(), cmp);

	for (auto it : v) {
		cout << it.first << '\n';
	}
}