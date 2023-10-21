#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_map<string, int> student;
	int K, L;
	cin >> K >> L;
	for (int i = 0; i < L; i++) {
		string s;
		cin >> s;
		student[s] = i;
	}
	vector<pair<string, int>> v;

	for (auto i : student) {
		v.push_back(i);
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < min(K, (int)v.size()); i++) {
		cout << v[i].first << '\n';
	}
	return 0;
}