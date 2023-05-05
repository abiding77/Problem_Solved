#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	int answer = 0;
	cin >> N;
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	for (int j = 0; j < N; j++) {
		int a;
		cin >> a;
		B.push_back(a);
	}
	sort(A.begin(), A.end(), greater<>());
	sort(B.begin(), B.end(), less<>());
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[i];
	}
	cout << answer;
}