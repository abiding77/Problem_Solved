#include <string>
#include <vector>

using namespace std;
int arr[10] = {0,1,2,3,4,5,6,7,8,9};

int solution(vector<int> numbers) {
    int answer = 0;
    for(int i=0; i<numbers.size(); i++){
        for(int j=0; j<10; j++){
            if(numbers[i] == arr[j]){
                arr[j] = 0;
                break;
            }
        }
    }
    for(int i=0; i<10; i++){
        answer += arr[i];
    }
    return answer;
}