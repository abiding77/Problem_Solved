#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> person;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	int rank = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int height, gram;
		cin >> height >> gram;
		person.push_back({ height, gram });
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (person[i].first < person[j].first && person[i].second < person[j].second)
				rank++;
		}
		cout << rank << " ";
		rank = 1;
	}
}