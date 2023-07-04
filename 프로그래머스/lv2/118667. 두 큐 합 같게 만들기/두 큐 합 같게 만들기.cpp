#include <string>
#include <numeric>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = accumulate(queue1.begin(),queue1.end(),0);
    long long sum2 = accumulate(queue2.begin(),queue2.end(),0);
    long long total = sum1 + sum2;
    if(total%2==1) return -1;
    int len = queue1.size();
    deque<int> q1,q2;
    
    while(!queue1.empty()){
        q1.push_front(queue1.back()); 
        queue1.pop_back();
    }
    while(!queue2.empty()){
        q2.push_front(queue2.back());
        queue2.pop_back();
    }
    int temp = 0;
    for(int i=0; i<3*len; i++){
        if(sum1 > sum2){
            sum1 -= q1.front();
            temp = q1.front();
            sum2 += temp;
            q1.pop_front();
            q2.push_back(temp);
            answer++;
        }
        else if(sum1 < sum2){
            sum2 -= q2.front();
            temp = q2.front();
            sum1 += temp;
            q2.pop_front();
            q1.push_back(temp);
            answer++;
        }
        else return answer;
    }
    return -1;
}