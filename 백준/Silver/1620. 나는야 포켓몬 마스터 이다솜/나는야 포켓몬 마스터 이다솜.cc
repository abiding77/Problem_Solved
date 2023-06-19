#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	map<string,int> pocketmon;
	vector<string> name;
	vector<string> answer;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		name.push_back(s);
		pocketmon.insert({ s, i });
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (s[0] >= 65 && s[0] <=90) {
			answer.push_back(to_string(pocketmon[s]));
		}
		else {
			answer.push_back(name[stoi(s) - 1]);
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}