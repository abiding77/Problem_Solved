#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> per;
vector<string> ans;
int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		string str;
		cin >> str;
		per[str]++;
		if (per[str] > 1)
			ans.push_back(str);
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}