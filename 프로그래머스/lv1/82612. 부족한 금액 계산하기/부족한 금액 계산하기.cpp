#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long dp[2505];
    long long answer = 0;
    dp[0] = price;
    
    for(int i=1; i<=count; i++){
        dp[i] = dp[i-1] + price * (i+1);
    }
    answer = dp[count-1] - money;
    if(answer <= 0 )
        return 0;
    return answer;
}