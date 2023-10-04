#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<string> word;
unordered_set<string>::iterator it;

vector<string> wordSplit(string s) {
	vector<string> res;
	string tmp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ',') {
			res.push_back(tmp);
			tmp = "";
		}
		else
			tmp += s[i];
	}
	res.push_back(tmp);
	return res;
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
		word.insert(s);
	}
	while (M--) {
		string s;
		cin >> s;
		vector<string> keyword = wordSplit(s);
		for (int i = 0; i < keyword.size(); i++) {
			if (word.find(keyword[i]) != word.end()) {
				it = word.find(keyword[i]);
				word.erase(it);
			}
		}
		cout << word.size() << '\n';
	}
}