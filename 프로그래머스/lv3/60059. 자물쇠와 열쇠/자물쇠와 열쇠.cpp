#include <string>
#include <vector>
#include <iostream>

int keyLen,lockLen,newLen;
using namespace std;

void rotate(vector<vector<int>>& graph){
    int m = graph.size();
    vector<vector<int>> newGraph(m,vector<int>(m,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            newGraph[i][j] = graph[m-j-1][i];
        }
    }
    graph = newGraph;
}
bool check(vector<vector<int>>& graph, vector<vector<int>>& key, int x, int y){
    bool ans = true;
    for(int i=0; i<keyLen; i++){
        for(int j=0; j<keyLen; j++){
            graph[i+x][j+y] += key[i][j];
        }
    }
    
    // 가운데 lock 영역이 모두 1이면 true, 아니면 false;
    for(int i=0; i<lockLen; i++){
        for(int j=0; j<lockLen; j++){
            if(graph[i+keyLen-1][j+keyLen-1] != 1){
                ans = false;
                break;
            }
        }
    }
    for(int i=0; i<keyLen; i++){
        for(int j=0; j<keyLen; j++){
            graph[i+x][j+y] -= key[i][j];
        }
    }
    return ans;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    keyLen = key.size();
    lockLen = lock.size();
    newLen = lockLen + 2 * (keyLen -1);
    vector<vector<int>> graph(newLen, vector<int>(newLen,0));
    // 새로운 길이의 그래프 정중앙에 자물쇠 위치
    for(int i=0; i<lockLen; i++){
        for(int j=0; j<lockLen; j++){
            graph[i+keyLen-1][j+keyLen-1] = lock[i][j];
        }
    }
    
    // 키 4번 회전
    for(int r=0; r<4; r++){
        for(int i=0; i<=newLen-keyLen; i++){
            for(int j=0; j<=newLen-keyLen; j++){
                if(check(graph,key,i,j)){
                    answer = true;
                    break;
                }
            }
        }
        rotate(key);
    }
    return answer;
}