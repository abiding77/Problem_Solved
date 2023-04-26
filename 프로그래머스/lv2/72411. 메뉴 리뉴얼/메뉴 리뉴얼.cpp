#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
map<string,int> combination[11];
int mxCount[11];
void comb(string str, int cnt, string result){
    if(str.length() == cnt){
        int num = result.length();
        combination[num][result]++;
        mxCount[num] = max(mxCount[num],combination[num][result]);
        return;
    }
    comb(str,cnt + 1,result);
    comb(str,cnt + 1,result + str[cnt]);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto order : orders){
        sort(order.begin(),order.end());
        comb(order,0,"");
    }
    for(auto num : course){
        for(auto x : combination[num]){
            if(x.second == mxCount[num] && x.second>=2){
                answer.push_back(x.first);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}