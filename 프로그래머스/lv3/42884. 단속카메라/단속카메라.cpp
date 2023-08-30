#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a , vector<int> b){
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),cmp);
    
    int camera = -30001;
    for(int i=0; i<routes.size(); i++){
        if(routes[i][0] > camera) {// 카메라 설치 위치가 진입 시기보다 앞이라면
            camera = routes[i][1];
            answer++;
        }
    }
    return answer;
}