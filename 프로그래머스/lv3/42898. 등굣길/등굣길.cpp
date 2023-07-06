#include <string>
#include <vector>


using namespace std;

int dp[101][101];

// 물웅덩이를 dp 테이블 -1
// dp[i][j] = dp[i-1][j] + dp[i][j-1] 로 탐색
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1] = 1;
    for(int i=0; i<puddles.size(); i++)
        dp[puddles[i][1]][puddles[i][0]] = -1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x = 0;
            int y = 0;
            if(dp[i][j] == -1) continue;
            if(dp[i-1][j] != -1) x = dp[i-1][j];
            if(dp[i][j-1] != -1) y = dp[i][j-1];
            dp[i][j] += (x+y)%1000000007;
        }
    }
    answer = dp[n][m];
    return answer;
}