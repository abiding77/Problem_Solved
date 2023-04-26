#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k;
char c[10];
bool isused[10];
vector<string> answer;
bool checkNum(string str) {
	for (int i = 0; i < k; i++) {
		if (c[i] == '>') {
			if (str[i] < str[i + 1]) return false;
		}
		else if (c[i] == '<') {
			if (str[i] > str[i + 1]) return false;
		}
	}
	return true;
}
void combination(int index, string str) {
	if (index == k + 1) {
		if (checkNum(str)) {
			answer.push_back(str);
			return;
		}
	}
	for (int i = 0; i <= 9; i++) {
		if (isused[i]) continue;
		isused[i] = true;
		combination(index + 1, str + to_string(i));
		isused[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}
	combination(0, "");
	auto p = minmax_element(answer.begin(), answer.end());
	cout << *p.second << '\n';
	cout << *p.first;
}