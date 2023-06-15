#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string tmp_answer = "";
    for(int i=1; i<food.size(); i++){
        for(int j=0; j<food[i]/2; j++){
            answer += to_string(i);
        }
    }
    tmp_answer = answer;
    reverse(answer.begin(),answer.end());
    tmp_answer += answer;
    int num = tmp_answer.length()/2;
    tmp_answer.insert(num,"0");
    cout << tmp_answer << " ";
    return tmp_answer;
}