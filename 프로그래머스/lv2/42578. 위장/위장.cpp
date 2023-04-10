#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> cody;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i=0; i<clothes.size(); i++){
        cody[clothes[i][1]]++;
    }
    for(auto it = cody.begin(); it!= cody.end(); it++){
        answer *= it->second + 1;
    }
    answer--;
    return answer;
}