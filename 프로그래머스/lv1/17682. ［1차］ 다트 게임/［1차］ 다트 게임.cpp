#include <string>
#include <math.h>

using namespace std;
int score[3];
int solution(string dartResult) {
    int answer = 0;
    int index = 0;
    int scores = 0;
    for(int i=0; i<3; i++){
        if(dartResult[index] == '1' && dartResult[index+1] == '0'){
            scores = 10;
            index++;
        } else {
            scores = dartResult[index] - '0';
        }
        score[i] = scores;
        index++;
        
        if(dartResult[index] == 'S'){
            score[i] = score[i]*1;
        } else if(dartResult[index] == 'D'){
            score[i] = pow(score[i],2);
        } else if(dartResult[index] == 'T'){
            score[i] = pow(score[i],3);
        }
        index++;
        
        if(dartResult[index] == '*'){
            if(i!=0){
                score[i-1] *= 2;
            }
            score[i] *= 2;
        } else if(dartResult[index] == '#'){
            score[i] *= -1;
        } else {
            continue;
        }
        index++;
    }
    for(int i=0; i<3; i++){
        answer += score[i];
    }
    return answer;
}