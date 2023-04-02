#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans1,ans2,ans3;
int arr1[5] = {1,2,3,4,5};
int arr2[8] = {2,1,2,3,2,4,2,5};
int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score;
    int ssize = answers.size();
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    int max = 0;
    for(int i=0; i<ssize; i++){
        int x1 = i%5;
        int x2 = i%8;
        int x3 = i%10;
        if(arr1[x1] == answers[i]) cnt1++;
        if(arr2[x2] == answers[i]) cnt2++;
        if(arr3[x3] == answers[i]) cnt3++;
        if(max <= cnt1) max = cnt1;
        if(max <= cnt2) max = cnt2;
        if(max <= cnt3) max = cnt3;
    }
    score.push_back(cnt1);
    score.push_back(cnt2);
    score.push_back(cnt3);
    for(int i=0; i<3; i++){
        if(score[i] == max)
            answer.push_back(i+1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}