#include <string>
#include <vector>
#include <set>

using namespace std;

bool visited[8];
set<string> str;

void DFS(vector<string>& user_id, vector<string>& banned_id, int index){
    if(banned_id.size() == index){
        string tmp;
        for(int i=0; i<user_id.size(); i++){
            if(visited[i] == true){
                tmp += user_id[i];
            }
        }
        str.insert(tmp);
        return;
    }
    for(int i=0; i<user_id.size(); i++){
        if(visited[i] == true) continue;
        if(user_id[i].size() != banned_id[index].size()) continue;
        bool check = true;
        for(int j=0; j<user_id[i].size(); j++){
            if(banned_id[index][j] == '*') continue;
            if(banned_id[index][j] != user_id[i][j]){
                check = false;
                break;
            }
        }
        if(check == true){
            visited[i] = true;
            DFS(user_id,banned_id,index+1);
            visited[i] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    DFS(user_id,banned_id,0);
    answer = str.size();
    return answer;
}