#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/*
▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
*/
using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    string tmp = "";
    // 변환 부분
    // 이부분을 수정하고
    for(auto ch : name){
        answer += min(91-ch,ch-'A');
    }
    int move = len - 1;
    int next = 0;
    for(int i=0; i<len; i++){
        next = i+1;
        while(next < len && name[next] == 'A') next++;
        move = min(move, i+(len-next)+ min(i,len-next));
    }
    answer += move;
    // 커서 부분
    // JAAAAAAB
    return answer;
}