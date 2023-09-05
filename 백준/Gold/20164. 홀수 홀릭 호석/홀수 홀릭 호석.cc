#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;


/*
수의 각 자리 숫자 중에서 홀수의 개수를 종이에 적는다.
수가 한 자리이면 더 이상 아무것도 하지 못하고 종료한다.
수가 두 자리이면 2개로 나눠서 합을 구하여 새로운 수로 생각한다.
수가 세 자리 이상이면 임의의 위치에서 끊어서 3개의 수로 분할하고, 3개를 더한 값을 새로운 수로 생각한다.
*/
int num;
int oddNum;
int maxNum, minNum = INT_MAX;
int checkNum(string num) {
	int ans = 0;
	for (int i = 0; i < num.length(); i++) {
		if (num[i] % 2 == 1) ans++;
	}
	return ans;
}
int addNum(string num) {
	int ans = 0;
	for (int i = 0; i < num.length(); i++) {
		ans += num[i] - '0';
	}
	return ans;
}
void DFS(int num, int total) {
	string solveNum = to_string(num);
	if (solveNum.length() == 1) { // 수가 한자리이면
		total += checkNum(solveNum);
		maxNum = max(maxNum, total); // 최대값 저장
		minNum = min(minNum, total); // 최소값 저장
		return;
	}
	else if (solveNum.length() == 2) { // 수가 두자리이면
		total += checkNum(solveNum);
		DFS(addNum(solveNum), total); // 2개로 나눠서 합을 구하여 새로운 수로 생각
	}
	else { // 세자리 이상이면
		total += checkNum(solveNum);
		for (int i = 1; i < solveNum.length()-1; i++) {
			string first, second, third; // 82019
			for (int j = i + 1; j < solveNum.length(); j++) { 
				first = solveNum.substr(0, i); // 0~i 자르기  8
				second = solveNum.substr(i, j - i); // i~ i+j-i; // 2
				third = solveNum.substr(j, solveNum.length() - j); // j~ 끝까지 019
				int num = stoi(first) + stoi(second) + stoi(third);
				DFS(num, total);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> num;
	DFS(num,0);
	cout << minNum << " " << maxNum;
}