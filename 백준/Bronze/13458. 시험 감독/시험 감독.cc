#include <iostream>

using namespace std;

int N;
int A[1000001];
int B, C;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long advisor = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		if (A[i] <= B) {
			advisor++;
		}
		else {
			advisor += (A[i] - B) / C + 1;
			if ((A[i] - B) % C != 0)
				advisor++;
		}
	}
	
	cout << advisor << '\n';
}