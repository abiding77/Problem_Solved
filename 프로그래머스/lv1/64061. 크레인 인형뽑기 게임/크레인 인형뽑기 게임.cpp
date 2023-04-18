#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> doll;
    for(int i=0; i<moves.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[j][moves[i]-1] != 0){
                if(!doll.empty() && doll.top() == board[j][moves[i]-1]){
                    doll.pop();
                    board[j][moves[i]-1] = 0;
                    answer += 2;
                    break;
                }
                else {
                    doll.push(board[j][moves[i]-1]);
                    board[j][moves[i]-1] = 0;
                    break;
                }
            }
        }
    }
    return answer;
}