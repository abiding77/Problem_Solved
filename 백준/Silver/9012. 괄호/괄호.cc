#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		string tmp;
		cin >> tmp;
		stack<char> ST;
		string ans = "YES";
		for (int i = 0; i < tmp.length(); i++) {
			
			if (tmp[i] == '(') {
				ST.push(tmp[i]);
			}
			else if (!ST.empty() && tmp[i] == ')' && ST.top() == '(') {
				ST.pop();
			}
			else {
				ans = "NO";
				break;
			}
		}
		if (!ST.empty())
			ans = "NO";
		cout << ans << '\n';
		
	}
}