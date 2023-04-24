#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <iostream>

using namespace std;
map<int,int> tuple_set;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    string tmp;
    for(int i=1; i<s.length(); i++){
        if(isdigit(s[i])){
            tmp += s[i];
            if(s[i+1] != ',' && s[i+1] != '}') continue;
            tuple_set[stoi(tmp)]++;
        }
        tmp = "";
    }
    vector<pair<int,int>> vv(tuple_set.begin(),tuple_set.end());
    // 2 4 , 1 3 , 3 2 , 4 1
    sort(vv.begin(), vv.end(), cmp);
    for(auto c : vv){
        answer.push_back(c.first);
    }
    return answer;
}