#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int length = s.length();
    char x = s[0];
    int x_num = 1, other_num = 0;
    for(int i=1; i<length; i++){
        if(x_num == other_num){
            answer++;
            x = s[i];
            x_num = 1;
            other_num = 0;
        } else{
            if(s[i] == x){
                x_num++;
            }
            else other_num++;
        }
    }
    answer++;
    return answer;
}