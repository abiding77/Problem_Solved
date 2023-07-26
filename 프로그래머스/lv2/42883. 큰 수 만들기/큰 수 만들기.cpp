#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int answerSize = number.length() - k;
    int startIdx = 0;
    for(int i=0; i<answerSize; i++){
        char maxNum = number[startIdx];
        int maxIdx = startIdx;
        for(int j=startIdx; j<=k+i; j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                maxIdx = j;
            }
        }
        startIdx = maxIdx+1;
        answer += maxNum;
    }
    return answer;
}