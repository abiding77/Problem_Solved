#include <string>
#include <vector>

using namespace std;

bool check[200];
void dfs(int cur_computers, int n, vector<vector<int> > computers){
    check[cur_computers] = true;
    for(int i=0; i<n; i++){
        if(!check[i] && computers[cur_computers][i] == 1){
            dfs(i,n,computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        if(!check[i]){
            dfs(i,n,computers);
            answer++;
        }
    }
    return answer;
}