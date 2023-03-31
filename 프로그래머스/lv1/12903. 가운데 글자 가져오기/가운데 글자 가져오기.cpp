#include <iostream>
#include <string>
#include <vector>

using namespace std;
string solution(string s) {
    string answer="";
    int len = s.length(); // 5
    int num = len/2; // 2
    if(len%2==0){
        answer.push_back(s[num-1]);
        answer.push_back(s[num]);
    }
    else{
        answer.push_back(s[num]);
    }
    return answer;    
}