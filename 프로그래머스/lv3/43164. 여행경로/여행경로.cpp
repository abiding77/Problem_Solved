#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> answer;
vector<vector<string>> ticket;
bool visited[10001];
bool isAnswer;
// [0][0] -> [0][1] -> [2][[0] -> [2][1] => [1][0] -> [1][1]
void DFS(string start, int cnt){
    answer.push_back(start);
    if(ticket.size() == cnt) {
        isAnswer = true;
    }
    for(int i=0; i<ticket.size(); i++){
        if(visited[i]) continue;
        if(ticket[i][0] == start){
            visited[i] = true;
            DFS(ticket[i][1],cnt+1);
            
            if(!isAnswer){
                answer.pop_back();
                visited[i] = false;
            }
        }
        
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end());
    ticket = tickets;
    DFS("ICN",0);
    return answer;
}