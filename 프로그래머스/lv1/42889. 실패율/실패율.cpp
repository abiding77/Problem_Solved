#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 스테이지에 도달했으나 아직 클리어하지 못한 플레이어 수 / 스테이지에 도달한 플레이어 수
bool cmp(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double,int>> fail_rate;
    int size = stages.size();
    for(int i=1; i<=N; i++){
        double clearNum = 0;
        double failNum = 0;
        for(int j=0; j<size; j++){
            if(stages[j] >= i){
                clearNum++;
            }
            if(stages[j] == i){
                failNum++;
            }
        }
        if(clearNum == 0){
            fail_rate.push_back({0,i});
        }
        else {
            fail_rate.push_back({failNum / clearNum,i});
        }
    }
    sort(fail_rate.begin(),fail_rate.end(),cmp);
    for(int i=0; i<fail_rate.size(); i++){
        answer.push_back(fail_rate[i].second);
    }
    return answer;
}