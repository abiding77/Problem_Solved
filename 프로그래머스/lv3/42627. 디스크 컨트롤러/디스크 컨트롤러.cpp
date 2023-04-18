#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct cmp {
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>,vector<vector<int>>,cmp> PQ;
    int current_time = 0;
    int total_time = 0;
    int cnt = 0;
    sort(jobs.begin(),jobs.end());
    while(cnt < jobs.size() || !PQ.empty()){
        if(cnt < jobs.size() && jobs[cnt][0] <= current_time){
            PQ.push(jobs[cnt++]);
            continue;
        }
        
        if(!PQ.empty()){
            current_time += PQ.top()[1];
            total_time += current_time - PQ.top()[0];
            PQ.pop();
        }
        else {
            current_time = jobs[cnt][0];
        }
    }
    answer = total_time / jobs.size();
    return answer;
}