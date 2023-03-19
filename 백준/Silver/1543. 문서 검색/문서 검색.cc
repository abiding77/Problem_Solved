#include <iostream>
#include <string>

using namespace std;

string orig;
string cmp;
int cnt = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	getline(cin, orig);
	
	getline(cin, cmp);
	for (int i = 0; i < orig.length(); i++) {
		bool flag = true;
		for (int j = 0; j < cmp.length(); j++) {
			if (orig[i + j] != cmp[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cnt++;
			i += cmp.length() - 1;
		}
	}
	cout << cnt;
}