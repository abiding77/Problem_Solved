#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int,int>> graph[51];
vector<int> dist;
void BFS(int N){
    priority_queue<pair<int,int>> PQ;
    PQ.push({0,1});
    dist[1] = 0;
    while(!PQ.empty()){
        int cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();
        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;
            
            if(dist[next] > cost + nCost){
                dist[next] = cost+nCost;
                PQ.push({-dist[next],next});
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist.resize(N+1,2e9);
    for(int i=0; i<road.size(); i++){
        int a = road[i][0], b = road[i][1], c =road[i][2];
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    BFS(N);
    for(int i=1; i<=N; i++){
        if(dist[i] <= K) answer++;
    }
    return answer;
}