#include <iostream>
#include <map>
#include <math.h>
#include <string>

using namespace std;

map<string, int> m;
float cnt;
string s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (getline(cin, s)) {
		cnt++;
		if (m.find(s) != m.end()) m[s] +=1;
		else m[s] = 1;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << (it->second / cnt) * 100 << '\n';
	}
	return 0;
}