#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> state;
    map<string,string> userInfo;
    for(int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        string str[3];
        string token;
        int index = 0;
        while(ss >> token){
            str[index++] = token;
        }
        if(str[0] == "Enter"){
            state.push_back("님이 들어왔습니다.");
            answer.push_back(str[1]);
            userInfo[str[1]] = str[2];
        }
        else if(str[0] == "Leave"){
            state.push_back("님이 나갔습니다.");
            answer.push_back(str[1]);
        } else {
            userInfo[str[1]] = str[2];
        }
    }
    for(int i=0; i<answer.size(); i++){
        answer[i] = userInfo[answer[i]] + state[i];
    }
    return answer;
}