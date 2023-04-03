#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>
/*
비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
*/
using namespace std;

int N;
vector<vector<int>> like(401, vector<int>());
vector<pair<int, int>> seat(401, { -1,-1 });
vector<vector<int>> map(21, vector<int>(21, -1));

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int satisfaction(int num) {
	int answer = 0;
	for (int i = 1; i <= num; i++) {
		int nx = seat[i].first;
		int ny = seat[i].second;

		int count = 0;
		for (int j = 0; j < 4; j++) {
			int adjnx = nx + dx[j];
			int adjny = ny + dy[j];
			if (adjnx < 0 || adjnx >= N || adjny < 0 || adjny >= N) continue;
			if (find(like[i].begin(), like[i].end(), map[adjnx][adjny]) != like[i].end()) count++;
		}
		if (count != 0) {
			answer += pow(10, count - 1);
		}
	}
	return answer;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
void selectSeat(int idx, vector<int> likeList) {
	vector<vector<int>> candidatesMap(21, vector<int>(21, 0)); // 후보 자리 
	vector<pair<int, int>> candidatesVec1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == -1) {
				candidatesVec1.push_back({ i,j });
			}
		}
	}
	int maxScore = 0;
	for (int i = 0; i < 4; i++) {
		pair<int, int> likeSeat = seat[likeList[i]];
		if (likeSeat.first == -1) continue;
		for (int j = 0; j < 4; j++) {
			int nx = likeSeat.first + dx[j];
			int ny = likeSeat.second + dy[j];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] != -1) continue;
			candidatesMap[nx][ny]++;
			if (candidatesMap[nx][ny] > maxScore) {
				maxScore = candidatesMap[nx][ny];
				candidatesVec1.clear();
				candidatesVec1.push_back({ nx,ny });
			}
			else if (candidatesMap[nx][ny] == maxScore) {
				candidatesVec1.push_back({ nx,ny });
			}
		}
	}
	if (candidatesVec1.size() == 1) {
		seat[idx] = { candidatesVec1[0].first,candidatesVec1[0].second };
		map[candidatesVec1[0].first][candidatesVec1[0].second] = idx;
	}
	else {
		vector<pair<int, int>> candidatesVec2(candidatesVec1);
		for (int i = 0; i < candidatesVec1.size(); i++) {
			int nx = candidatesVec1[i].first;
			int ny = candidatesVec1[i].second;
			for (int j = 0; j < 4; j++) {
				int adjnx = nx + dx[j];
				int adjny = ny + dy[j];
				if (adjnx >= 0 && adjnx < N && adjny >= 0 && adjny < N && map[adjnx][adjny] == -1) {
					candidatesMap[nx][ny]++;
					if (candidatesMap[nx][ny] > maxScore) {
						maxScore = candidatesMap[nx][ny];
						candidatesVec2.clear();
						candidatesVec2.push_back({ nx,ny });
					}
					else if (candidatesMap[nx][ny] == maxScore) {
						candidatesVec2.push_back({ nx,ny });
					}
				}
			}
		}
		if (candidatesVec2.size() == 1) {
			seat[idx] = { candidatesVec2[0].first,candidatesVec2[0].second };
			map[candidatesVec2[0].first][candidatesVec2[0].second] = idx;
		}
		else {
			sort(candidatesVec2.begin(), candidatesVec2.end(), cmp);
			seat[idx] = { candidatesVec2[0].first, candidatesVec2[0].second };
			map[candidatesVec2[0].first][candidatesVec2[0].second] = idx;
		}
	}
	like[idx] = likeList;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int num = N * N;
	int idx;
	for (int i = 0; i < num; i++) {
		cin >> idx;
		int likeIdx;
		vector<int> likeList;
		for (int i = 0; i < 4; i++) {
			cin >> likeIdx;
			likeList.push_back(likeIdx);
		}

		selectSeat(idx, likeList);
	}
	int answer = satisfaction(num);

	cout << answer;
	return 0;
}