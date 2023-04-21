#include <string>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;
vector<string> graph;
vector<vector<int>> square;
int answer = 0;
void deleteSquare(int m, int n){
    // 인접 상 하 좌 우 비교시 범위를 넘어가면 안됨. m,n -1 범위까지만 탐색
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            char c = graph[i][j];
            if(c== '0') continue;
            if(graph[i][j+1] == c && graph[i+1][j+1] == c && graph[i+1][j] == c){
                square.push_back({i,j});
            }
        }
    }
    // 삭제
    if(square.size() != 0){
        for(int i=0; i<square.size(); i++){
            int row = square[i][0];
            int col = square[i][1];
            //cout << row << " " << col << '\n';
            if(graph[row][col] != '0'){
                graph[row][col] = '0';
                answer++;
            }
            if(graph[row][col+1] != '0'){
                graph[row][col+1] = '0';
                answer++;
            }
            if(graph[row+1][col] != '0'){
                graph[row+1][col] = '0';
                answer++;
            }
            if(graph[row+1][col+1] != '0'){
                graph[row+1][col+1] = '0';
                answer++;
            }
        }
        int down = 0;
        bool flag = false;
        for(int j=0; j<n; j++){
            flag = false;
            for(int i=m-1; i>=0; i--){
                if(graph[i][j] == '0'){
                    if(!flag){
                        flag = true;
                        down = i;
                    }
                } else {
                    if(flag){
                        graph[down][j] = graph[i][j];
                        graph[i][j] = '0';
                        down--;
                    }
                }
            }
        }
        square.clear();
        deleteSquare(m,n);
    }
}
int solution(int m, int n, vector<string> board) {
    graph = board;
    deleteSquare(m,n);
    return answer;
}