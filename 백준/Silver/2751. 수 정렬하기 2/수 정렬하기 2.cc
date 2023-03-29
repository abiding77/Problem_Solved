#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}
}