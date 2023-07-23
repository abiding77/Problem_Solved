#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<int>> scores;

void addInput(string* s, int score){
    for(int i=0; i<16; i++){
        string str = "";
        int a = i;
        for(int j=3; j>=0; j--){
            if(a<=0 || a%2==0) str = '-' + str;
            else str = s[j]+str;
            a/=2;
        }
        scores[str].push_back(score);
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string s[4], str = "";
    for(int i=0; i<info.size(); i++){
        stringstream ss(info[i]);
        ss >> s[0] >> s[1] >> s[2] >> s[3] >> str;
        addInput(s,(int)stoi(str));
    }
    for(auto it = scores.begin(); it != scores.end(); it++)
        sort(it->second.begin(), it->second.end());
    
    for(int i=0; i<query.size(); i++){
        int score;
        stringstream ss(query[i]);
        ss >> s[0] >> str >> s[1] >> str >> s[2] >> str >> s[3] >> str;
        score = stoi(str);
        vector<int> v = scores[s[0]+s[1]+s[2]+s[3]];
        if(v.size() != 0){
            auto it = lower_bound(v.begin(),v.end(),score);
            answer.push_back(v.size() - (it-v.begin()));
        }
        else answer.push_back(0);
    }
    return answer;
}