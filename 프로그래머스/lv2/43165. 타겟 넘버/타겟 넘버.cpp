#include <string>
#include <vector>

using namespace std;

int answer;

void findTarget(vector<int> numbers, int target, int sum, int index){
    if(index == numbers.size()){
        if(sum == target){
            answer++;
        }
        return;
    }
    findTarget(numbers,target,sum + numbers[index], index+1);
    findTarget(numbers,target,sum - numbers[index], index+1);
}
int solution(vector<int> numbers, int target) {
    findTarget(numbers,target,0,0);
    
    return answer;
}
