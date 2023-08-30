#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    int answer = 0;
    cin >> N;
    while (N >= 0) {
        if (N % 5 == 0) {
            answer += N / 5;
            cout << answer << '\n';
            return 0;
        }
        N -= 3;
        answer++;
    }
    cout << -1 << '\n';
}