#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    // 1단계
    transform(new_id.begin(),new_id.end(),new_id.begin(), ::tolower);
    string temp = "";
    // 2단계
    for(int i=0; i<new_id.length(); i++){
        if(isalpha(new_id[i]) || isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            temp += new_id[i];
        }
    }
    new_id = temp;
    temp = "";
    // 3단계
    for(int i=0; i<new_id.length(); i++){
        if(new_id[i-1] == '.' && new_id[i] == '.') continue;
        temp += new_id[i];
    }
    new_id = temp;
    // 4단계
    if(new_id.front() == '.') new_id.erase(0,1);
    if(new_id.back() == '.') new_id.pop_back();
    // 5단계
    if(new_id.length() == 0) new_id = "a";
    // 6단계
    if(new_id.length() >= 16) new_id.erase(new_id.begin() + 15 , new_id.end());
    if(new_id.back() == '.') new_id.pop_back();
    // 7단계
    while(new_id.length() < 3)
        new_id += new_id.back();
    
    answer = new_id;
    return answer;
}