#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


vector<vector<int>> graph;
vector<int> dist;

void BFS(int start){
    dist[start] = 0;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int next : graph[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                Q.push(next);
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int M = edge.size();
    int N = edge[0].size();
    graph.resize(n+1);
    dist.resize(n+1,-1);
    for(int i=0; i<edge.size(); i++){
        int u = edge[i][0];
        int v = edge[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(1);
    
    int maxDist = -1;
    for(int i=1;  i<=n; i++){
        if(dist[i] > maxDist){ 
            maxDist = dist[i];
            answer = 1;
        }
        else if(dist[i] == maxDist){
            answer++;
        }
    }
    return answer;
}