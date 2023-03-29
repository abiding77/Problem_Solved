#include <iostream>
#include <math.h>

using namespace std;

int N;
int answer = 0;
int prime[1001];
bool findPrime(int n) {
	if (n<=1 ) return false;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> prime[i];
	}
	for (int i = 0; i < N; i++) {
		if (findPrime(prime[i]))
			answer++;
	}
	cout << answer;
}