#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> map;
    for(int i=0; i<participant.size(); i++){
        if(map.end() == map.find(participant[i]))
            map.insert({participant[i],1});
        else
            map[participant[i]]++;
    }
    for(int i=0; i<completion.size(); i++){
        map[completion[i]]--;
    }
    for(int i=0; i<participant.size(); i++){
        if(map[participant[i]] > 0){
            answer = participant[i];
            break;
        }
    }
    return answer;
}