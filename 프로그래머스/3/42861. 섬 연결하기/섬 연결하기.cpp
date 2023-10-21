#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

bool visited[101];
vector<pair<int,int>> V[101];
priority_queue<pair<int,int>> PQ;
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0; i<costs.size(); i++){
        int N1 = costs[i][0];
        int N2 = costs[i][1];
        int cost = costs[i][2];
        V[N1].push_back({N2,cost});
        V[N2].push_back({N1,cost});
    }
    
    for(int i=0; i<V[0].size(); i++){
        int next = V[0][i].first;
        int nCost = V[0][i].second;
        PQ.push({-nCost,next});
    }
    visited[0] = true;
    while(!PQ.empty()){
        int dist = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();
        
        if(visited[cur] == false){
            visited[cur] = true;
            answer += dist;
            
            for(int i=0; i<V[cur].size(); i++){
                int next = V[cur][i].first;
                int ndist = V[cur][i].second;
                if(!visited[next]) PQ.push({-ndist,next});
            }
        }
    }
    return answer;
}