#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

int answer;
bool checkPrime(int n){
    if(n<2) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}
void DFS(int idx, int cnt , int sum , vector<int> nums){
    if(cnt == 3){
        if(checkPrime(sum)) answer++;
        return;
    } else {
        for(int i=idx; i<nums.size(); i++){
            DFS(i+1,cnt+1,sum+nums[i],nums);
        }
    }
}
int solution(vector<int> nums) {
    DFS(0,0,0,nums);

    return answer;
}