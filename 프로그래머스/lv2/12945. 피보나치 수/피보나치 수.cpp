#include <string>
#include <vector>

using namespace std;

int fibo[100001];
int m = 1234567;
int solution(int n) {
    int answer = 0;
    int ssize = n;
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<=ssize; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2]) %m;
    }
    answer = fibo[ssize];
    return answer;
}