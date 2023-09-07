#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


void DFS(string orig, string target) {
	if (orig == target) {
		cout << 1;
		exit(0);
	}
	if (orig.length() > target.length()) return;
	if (target.back() == 'A') {
		string tmp = target;
		tmp.erase(tmp.size()-1);
		DFS(orig, tmp);
	}
	if (target[0] == 'B') {
		string tmp = target;
		reverse(tmp.begin(), tmp.end());
		tmp.erase(tmp.size()-1);
		DFS(orig, tmp);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	cin >> s >> t;
	DFS(s, t);
	cout << 0;
	return 0;
}