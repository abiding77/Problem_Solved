#include <string>
#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    vector<int> result;
    for(int i=0; i<=discount.size()-10; i++){
        vector<int> temp(number.begin(),number.end());
        for(int j=i; j<i+10; j++){
            for(int k=0; k<want.size(); k++){
                if(discount[j] == want[k]){
                    if(temp[k] > 0) temp[k]--;
                }
            }
        }
        int sum = accumulate(temp.begin(),temp.end(),0);
        result.push_back(sum);
    }
    for(int i=0; i<result.size(); i++){
        if(result[i] == 0) answer++;
    }
    return answer;
}