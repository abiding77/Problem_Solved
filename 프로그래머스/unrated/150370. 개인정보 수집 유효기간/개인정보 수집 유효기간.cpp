#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> priv;
    map<char,int> m;
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,2));
    int day = stoi(today.substr(8,2));
    int total = (year - 2000) * 12 * 28 + month * 28 + day;
    
    for(int i=0; i<terms.size(); i++){
        stringstream ss(terms[i]);
        char alpha; int dates;
        ss >> alpha >> dates;
        m[alpha] = dates;
    }
    
    for(int i=0; i<privacies.size(); i++){
        stringstream str(privacies[i]);
        string s1; char s2;
        str >> s1 >> s2;
        int tmp_year = stoi(s1.substr(0,4));
        int tmp_month = stoi(s1.substr(5,2));
        int tmp_day = stoi(s1.substr(8,2));
        int tmp_total = (tmp_year - 2000) * 12 * 28 + tmp_month * 28 + tmp_day + (m[s2] * 28 -1);
        priv.push_back(tmp_total);
    }
    for(int i=0; i<priv.size(); i++){
        if(priv[i] < total){
            answer.push_back(i+1);
        }
    }
    return answer;
}