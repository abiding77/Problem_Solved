#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string s;
vector<string> book;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int ssize = s.length();
	for (int i = 0; i < ssize; i++) {
		book.push_back(s.substr(i,ssize));
	}
	sort(book.begin(), book.end());
	for (auto i : book) {
		cout << i << '\n';
	}
}