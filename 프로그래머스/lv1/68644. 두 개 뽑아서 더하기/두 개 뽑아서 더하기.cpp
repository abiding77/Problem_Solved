#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> result;
    int size = numbers.size();
    int sum = 0;
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            sum = numbers[i] + numbers[j];
            result.insert(sum);
        }
    }
    answer.assign(result.begin(),result.end());
    return answer;
}