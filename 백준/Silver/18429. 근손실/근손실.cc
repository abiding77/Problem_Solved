#include <iostream>
#include <vector>
using namespace std;

int n, k;
int cnt = 0;
int arr[8];
bool visit[8];
vector<int> plan;
void dfs(int idx) {
	if (idx == n) {
		int check = 500;
		for (int i = 0; i < plan.size(); i++) {
			check = check + plan[i] - k;
			if (check < 500) {
				return;
			}
		}
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			plan.push_back(arr[i]);
			dfs(idx + 1);
			plan.pop_back();
			visit[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dfs(1);
	cout << cnt;
}