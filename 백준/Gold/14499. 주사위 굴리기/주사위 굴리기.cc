#include <iostream>
#include <vector>
using namespace std;

int mapp[21][21];
int N, M, x, y, K;
vector<int> dice(7);
int order[1001];
int dx[5] = {0, 1,-1,0,0 };
int dy[5] = {0, 0, 0 , -1 ,1 };

void rollEast() {
	dice = { 0,dice[4],dice[2],dice[1],dice[6],dice[5],dice[3] };
}
void rollWest() {
	dice = { 0,dice[3],dice[2],dice[6],dice[1],dice[5],dice[4] };
}
void rollNorth() {
	dice = { 0,dice[5],dice[1],dice[3],dice[4],dice[6],dice[2] };
}
void rollSouth() {
	dice = { 0,dice[2],dice[6],dice[3],dice[4],dice[1],dice[5] };
}
void roll(int order) {
	switch (order) {
	case 1:
		rollEast();
		break;
	case 2:
		rollWest();
		break;
	case 3:
		rollNorth();
		break;
	case 4:
		rollSouth();
		break;
	default:
		break;
	}
}
void play() {
	for (int i = 0; i < K; i++) {
		int mx = dx[order[i]];
		int my = dy[order[i]];
		if (x + mx >= M || x + mx < 0 || y + my >= N || y + my < 0)
			continue;
		x += mx;
		y += my;
		roll(order[i]);
		cout << dice[1] << '\n';

		if (mapp[y][x] == 0)
			mapp[y][x] = dice[6];
		else {
			dice[6] = mapp[y][x];
			mapp[y][x] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> y >> x >> K;
	for(int i=0; i<N; i++){
		for (int j = 0; j < M; j++) {
			cin >> mapp[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}
	play();
}