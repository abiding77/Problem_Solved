#include <iostream>
#include <string>

using namespace std;


/*
모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
*/

bool checkAlpha(char c) { // 모음이면 true , 자음이면 false
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
	return false;
}
bool checkString(string s) {
	int mo = 0;
	int ja = 0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (checkAlpha(s[i])) {
			flag = true;
			mo++;
			ja = 0;
		}
		else {
			ja++;
			mo = 0;
		}

		if (mo == 3 || ja == 3) return false;

		if (i > 0 && s[i] == s[i - 1] && !(s[i] == 'e' || s[i] == 'o')) return false;
	}
	return flag;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	while (1) {
		cin >> s;
		if (s == "end") break;
		bool flag = checkString(s);
		if (flag) cout << "<" << s << "> is acceptable.\n";
		else cout << "<" << s << "> is not acceptable.\n";
	}
}