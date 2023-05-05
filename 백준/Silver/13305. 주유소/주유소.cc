#include <iostream>
#include <climits>
using namespace std;

int dist[100002];
int cost[100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	long long total = 0;
	int minCost = INT_MAX;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> dist[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}
	
	for (int i = 1; i < N; i++) {
		if (cost[i] < minCost) minCost = cost[i];
		total += (long long)minCost * (long long)dist[i];
	}
	cout << total;
}