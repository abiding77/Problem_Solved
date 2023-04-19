#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string temp = "";
    while(n>0){
        temp += to_string(n%3);
        n /= 3;
    }
    reverse(temp.begin(),temp.end());
    for(int i=0; i<temp.length(); i++){
        string number = temp.substr(i,1);
        int num = stoi(number);
        answer += num * pow(3,i);
    }
    return answer;
}