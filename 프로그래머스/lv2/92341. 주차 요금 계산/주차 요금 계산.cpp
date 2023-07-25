#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;
unordered_map<string,int> um;
unordered_map<string,int> timeBoard;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i=0; i<records.size(); i++){
        stringstream ss(records[i]);
        string time, number, type;
        
        ss >> time >> number >> type;
        
        string T = time.substr(0,2);
        string M = time.substr(3,2);
        
        if(type == "OUT") {
        // 출차
            if(timeBoard.find(number) != timeBoard.end()) {
                timeBoard[number] += (stoi(T) * 60 + stoi(M)) - um[number];
            }  else {
                timeBoard[number] = (stoi(T) * 60 + stoi(M)) - um[number];
            }
            // 출차처리
            um.erase(number);
                    
        } else {
        // 입차
            um[number] = stoi(T) * 60 + stoi(M);
        }
    }
    //남아있는거
    
    for(auto it : um){
        timeBoard[it.first] += 1439-it.second;
    }
    vector<pair<string, int>> sortedTimeBoard(timeBoard.begin(), timeBoard.end());
    sort(sortedTimeBoard.begin(), sortedTimeBoard.end());

    // for (auto elem : sortedTimeBoard) {
    //     cout << elem.first << " " << elem.second << '\n';
    // }
    for(auto it : sortedTimeBoard){
        double sum = 0;
        if(it.second <= fees[0]) sum = fees[1];
        else {
            double time = it.second - fees[0];
            sum += fees[1];
            cout << ceil(time/fees[2]) << '\n';
            sum += ceil(time/fees[2]) * fees[3];
        }
        answer.push_back(sum);
    }
    
    
    
    
    
    return answer;
}