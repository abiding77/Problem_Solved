#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int size = lottos.size();
    int answer_cnt = 0;
    int zero_cnt = 0;
    for(int i=0; i<size; i++){
        if(lottos[i] == 0){
            zero_cnt++;
            continue;
        }
        for(int j=0; j<size; j++){
            if(lottos[i] == win_nums[j])
                answer_cnt++;
        }
    }
    int sum = answer_cnt + zero_cnt;
    switch(sum){
        case 0:
        case 1:
            answer.push_back(6);
            break;
        case 2:
            answer.push_back(5);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 5:
            answer.push_back(2);
            break;
        case 6:
            answer.push_back(1);
            break;
    }
    switch(answer_cnt){
        case 0:
        case 1:
            answer.push_back(6);
            break;
        case 2:
            answer.push_back(5);
            break;
        case 3:
            answer.push_back(4);
            break;
        case 4:
            answer.push_back(3);
            break;
        case 5:
            answer.push_back(2);
            break;
        case 6:
            answer.push_back(1);
            break;
    }
    return answer;
}