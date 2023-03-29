#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int arr[3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 3);
		if (!(arr[0] && arr[1] && arr[2]))
			return 0;
		if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
}