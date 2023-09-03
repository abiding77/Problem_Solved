#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    long long minNum = 1; // 가장 짧은 시간
    long long maxNum = (long long) n * times.back(); // 가장 오래걸리는 시간 
    while(minNum <= maxNum){
        long long avg = (minNum + maxNum) / 2;
        long long tmp = 0;
        for(int i=0; i<times.size(); i++){
            tmp += avg / times[i];
        }
        // tmp = 7 , avg = 30
        if(tmp < n){ 
            minNum = avg+1;
        } else {
            answer = avg;
            maxNum = avg-1;
        }
        cout << avg << " ";
    }
    return answer;
}