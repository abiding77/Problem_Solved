#include <string>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int leftCount;
int rightCount;

bool checkSigned(string p){
    stack<char> ST;
    for(int i=0; i<p.length(); i++){
        if(p[i] == '(') ST.push('(');
        else {
            if(ST.empty()) return false;
            ST.pop();
        }
    }
    if(ST.size() > 0)
        return false;
    return true;
}
string solution(string p) {
    string answer = "";
    // 1. 입력이 빈 문자열인 경우, 빈 문자열 반환
    if(p.empty())
        return "";
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
    string u,v;
    int len = p.length();
    for(int i=0; i<len; i++){
        if(p[i] == '(') leftCount++;
        else if(p[i] == ')') rightCount++;
        
        if(leftCount == rightCount){
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
    // 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
    if(checkSigned(u)){
        v = solution(v);
        answer = u+v;
        return answer;
    }
    // 4. 문자열 u가 올바른 괄호 문자열이 아니라면
    else {
        // 4-1 빈 문자열에 첫번째 문자로 ( 붙임.
        answer+="(";
        // 4-2 문자열 v에 대해 1단계부터 재귀적 결과 이어붙임
        answer += solution(v);
        // 4-3 ) 붙임.
        answer+=")";
        // 4-4 u의 첫번째와 마지막 문자를 제거함
        u.erase(0,1);
        u.pop_back();
        for(int i=0; i<u.length(); i++){
            if(u[i] == '(') answer+=')';
            else if(u[i] == ')') answer+='(';
        }
        
    return answer;
    }
}