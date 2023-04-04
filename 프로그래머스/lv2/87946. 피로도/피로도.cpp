#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(),dungeons.end());
    do{
        int count = 0;
        int now_k = k;
        for(int i=0; i<dungeons.size(); i++){
            if(now_k >= dungeons[i][0]){
                now_k -= dungeons[i][1];
                count++;
            }
            else {
                break;
            }
        }
        answer = max(answer,count);
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    return answer;
}