#include <iostream>

using namespace std;

int light[102];
int N;
int student;

void changeByBoy(int num) {
	for (int i = 1; i <= N; i++) {
		if (i % num == 0) light[i] = !light[i];
	}
}

void changeByGirl(int num) {
	int left = num - 1;
	int right = num + 1;
	light[num] = !light[num];
	while (left >= 1 && right <= N) {
		if (light[left] != light[right]) break;
		light[left] = !light[left];
		light[right] = !light[right];
		left--;
		right++;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> light[i];
	}
	cin >> student;
	for (int i = 0; i < student; i++) {
		int sex, number;
		cin >> sex >> number;
		if (sex == 1) {
			changeByBoy(number);
		}
		else {
			changeByGirl(number);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << light[i] << " ";
		if (i % 20 == 0) cout << '\n';
	}
}