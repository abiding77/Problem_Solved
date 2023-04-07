#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int answer = 999;
bool vis[50];
bool checkWords(string a, string b){
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]){
            cnt++;
        }
    }
    if(cnt==1){
        return true;
    }
    return false;
}
void DFS(string begin, string target, vector<string> words,int step){
    if(answer <= step)
        return;
    if(begin==target){
        answer = min(answer,step);
        return;
    }
    for(int i=0;  i<words.size(); i++){
        if(checkWords(begin,words[i]) && !vis[i]){
            vis[i] = true;
            DFS(words[i],target,words,step+1);
            vis[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    
    DFS(begin,target,words,0);
    if(answer==999)
        return 0;
    return answer;
}