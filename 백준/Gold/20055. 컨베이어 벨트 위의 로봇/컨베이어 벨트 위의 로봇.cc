#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int> recover;
deque<bool> conveyer;
int N, K;

void rotate() {
	conveyer.push_front(conveyer.back());
	conveyer.pop_back();
	
	recover.push_front(recover.back());
	recover.pop_back();
	conveyer[N - 1] = false;
}
void move() {
	for (int i = N - 2; i >= 0; i--) {
		if ((!conveyer[i + 1]) && (recover[i + 1] > 0) && (conveyer[i])) {
			conveyer[i] = false;
			conveyer[i + 1] = true;
			recover[i + 1]--;
		}
	}
	conveyer[N - 1] = false;
}
void insertRobot() {
	if (!conveyer[0] && recover[0] > 0) {
		conveyer[0] = true;
		recover[0]--;
	}
}
int check() {
	int c_count = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (recover[i] == 0)
			c_count++;
	}
	return c_count;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int stage = 1;
	for (int i = 0; i < 2 * N; i++) {
		int in;
		cin >> in;
		recover.push_back(in);
		conveyer.push_back(false);
	}
	while (1) {
		rotate();
		move();
		insertRobot();
		int c = check();
		if (c >= K) {
			cout << stage << '\n';
			return 0;
		}
		stage++;
	}
	return 0;
}