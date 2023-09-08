#include <iostream>
#include <cstring>

using namespace std;

int arr[21];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int P;
	cin >> P;
	for(int num=1; num<=P; num++) {
		int T;
		int walk = 0;
		cin >> T;
		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < 20; i++) {
			for (int j = i; j < 20; j++) {
				if (arr[i] > arr[j]) walk++;
			}
		}
		cout << num << " " << walk << '\n';
		memset(arr, 0, sizeof(arr));
	}
}