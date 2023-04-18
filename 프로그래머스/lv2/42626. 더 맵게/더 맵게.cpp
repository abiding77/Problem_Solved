#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int ssize = scoville.size();
    priority_queue<int, vector<int>, greater<int>> PQ(scoville.begin(),scoville.end());
    while(PQ.size() > 1 && PQ.top() < K){
        int first = PQ.top();
        PQ.pop();
        int second = PQ.top();
        PQ.pop();
        PQ.push(first + (second*2));
        answer++;
    }
    if(PQ.top() < K)
        return -1;
    return answer;
}