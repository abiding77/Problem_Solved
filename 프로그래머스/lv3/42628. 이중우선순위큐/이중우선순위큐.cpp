#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int size = 0;
    priority_queue<int,vector<int>,greater<int>> min_pq;
    priority_queue<int,vector<int>,less<int>> max_pq;
    for(int i=0; i<operations.size(); i++){
        string number = operations[i].substr(2,operations[i].length());
        if(operations[i][0] == 'I'){
            min_pq.push(stoi(number));
            max_pq.push(stoi(number));
            size++;
        }
        else if(operations[i][0] == 'D' && size > 0){
            if(number == "1"){
                max_pq.pop();
            } else if(number== "-1") {
                min_pq.pop();
            }
            size--;
                if(size ==0){
                    while(!min_pq.empty()){
                        min_pq.pop();
                    }
                    while(!max_pq.empty()){
                        max_pq.pop();
                    }
                }     
        }
    }
    if(size == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    return answer;
}