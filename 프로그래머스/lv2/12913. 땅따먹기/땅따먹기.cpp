#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size()-1;
    for(int i=0; i<N; i++){
        land[i+1][0] += max(land[i][1],max(land[i][2],land[i][3]));
        land[i+1][1] += max(land[i][0],max(land[i][2],land[i][3]));
        land[i+1][2] += max(land[i][0],max(land[i][1],land[i][3]));
        land[i+1][3] += max(land[i][0],max(land[i][1],land[i][2]));
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    return max(land[N][0], max(land[N][1],max(land[N][2],land[N][3])));
}