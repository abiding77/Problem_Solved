#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int light[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> light[i];
    }

    int left = 0;
    int right = 100000;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int flag = 0;

        if (light[0] > mid) flag = 1;

        for (int i = 0; i < M - 1; i++) {
            if (light[i + 1] - light[i] > mid * 2) {
                flag = 1;
                break;
            }
        }

        if (N - light[M - 1] > mid) flag = 1;

        if (!flag) {
            answer = mid;  // 현재 mid 값으로 가능하므로 정답 갱신
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;
}
