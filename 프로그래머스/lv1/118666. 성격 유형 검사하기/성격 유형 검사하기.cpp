#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> MBTI;
    int size = survey.size();
    for(int i=0; i<size; i++){
        int score = choices[i];
        switch(score){
            case 1:
                MBTI[survey[i][0]]+= 3;
                break;
            case 2:
                MBTI[survey[i][0]]+= 2;
                break;
            case 3:
                MBTI[survey[i][0]]++;
                break;
            case 4:
                break;
            case 5:
                MBTI[survey[i][1]]++;
                break;
            case 6:
                MBTI[survey[i][1]]+=2;
                break;
            case 7:
                MBTI[survey[i][1]]+= 3;
                break;
        }
    }
    answer += MBTI['R'] >= MBTI['T'] ? "R" : "T";
    answer += MBTI['C'] >= MBTI['F'] ? "C" : "F";
    answer += MBTI['J'] >= MBTI['M'] ? "J" : "M";
    answer += MBTI['A'] >= MBTI['N'] ? "A" : "N";
    return answer;
}