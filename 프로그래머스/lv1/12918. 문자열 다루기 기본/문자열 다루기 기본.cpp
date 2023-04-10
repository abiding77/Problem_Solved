#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int ssize = s.length();
    if (ssize != 4 && ssize != 6){
        return false;
    }
    for(int i=0; i<ssize; i++){
        if(!(s[i] >= '0' && s[i] <= '9')){
            return false;
        }
    }
    return true;
}