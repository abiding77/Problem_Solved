#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


vector<int> prime;
int arr[10001];

bool checkPrime(int num) {
	if (num < 2) return false;
	else {
		for (int i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) return false;
		}
	}
	return true;
}

long long LCM() {
	long long ans = 1;
	sort(prime.begin(), prime.end());
	prime.erase(unique(prime.begin(), prime.end()), prime.end());
	for (int i = 0; i < prime.size(); i++) {
		ans *= prime[i];
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (checkPrime(a)) prime.push_back(a);
	}
	if (prime.empty()) cout << -1;
	else cout << LCM();
}