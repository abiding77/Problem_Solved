#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int size = number.size();
    int sum = 0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                sum = number[i]+number[j]+number[k];
                if(sum ==0) answer++;
            }
        }
    }
    return answer;
}