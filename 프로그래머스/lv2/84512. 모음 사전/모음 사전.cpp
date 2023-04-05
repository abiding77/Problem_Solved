#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<char> collection = {'A','E','I','O','U'};
vector<string> dic;
void DFS(string word,int len){
    if(len == word.length()){
        dic.push_back(word);
        return;
    }
    int ssize = collection.size();
    for(int i=0; i<ssize; i++){
        DFS(word+collection[i],len);
    }
}
int solution(string word) {
    int answer = 0;
    string tmp = "";
    for(int i=1; i<=5; i++){
        DFS(tmp,i);
    }
    sort(dic.begin(),dic.end());
    for(int i=0; i<dic.size(); i++){
        if(word == dic[i]){
            return i+1;
        }
    }
}