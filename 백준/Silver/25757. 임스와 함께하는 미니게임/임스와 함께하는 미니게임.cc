#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> person;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	char T;
	int gamePlay = 0;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		person.insert(s);
	}
	if (T == 'Y') {
		gamePlay = person.size();
	}
	else if (T == 'F') {
		gamePlay = person.size() / 2;
	}
	else {
		gamePlay = person.size() / 3;
	}

	cout << gamePlay;
}