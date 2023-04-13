#include <string>
#include <algorithm>
#include <map>
#include <set>
#define MUL 65536
using namespace std;

map<string,int> A;
map<string,int> B;
set<string> strCollector;
int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(),str1.end(),str1.begin(), ::toupper);
    transform(str2.begin(),str2.end(),str2.begin(), ::toupper);
    string temp;
    for(int i=0; i<str1.length()-1; i++){
        if((str1[i] >= 'A' && str1[i] <= 'Z') && (str1[i+1] >= 'A' && str1[i+1] <= 'Z')){
            temp = str1.substr(i,2);
            A[temp]++;
            strCollector.insert(temp);
        }
    }
    for(int i=0; i<str2.length()-1; i++){
        if((str2[i] >= 'A' && str2[i] <= 'Z') && (str2[i+1] >= 'A' && str2[i+1] <= 'Z')){
            temp = str2.substr(i,2);
            B[temp]++;
            strCollector.insert(temp);
        }
    }
    int duplicateNum = 0;
    int allNum = 0;
    for(auto iter : strCollector){
        duplicateNum += min(A[iter],B[iter]);
        allNum += max(A[iter],B[iter]);
    }
    if(duplicateNum == 0 && allNum == 0) return MUL;
    answer = MUL*duplicateNum/allNum;
    return answer;
}