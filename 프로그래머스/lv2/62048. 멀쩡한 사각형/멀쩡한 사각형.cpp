#include <iostream>

using namespace std;

int gcd(int a , int b){
    int r = 0;
    while(b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
long long solution(int w,int h) {
    long long answer = 1;
    int num = gcd(w,h);
    answer = (long long)w * (long long)h - (w+h);
    answer += num;
    return answer;
}