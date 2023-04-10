#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int index;
bool cmp(string a, string b){
    if(a[index] == b[index])
        return a < b;
    return a[index] < b[index];
}
vector<string> solution(vector<string> strings, int n) {
    int ssize = strings.size();
    for(int i=0; i<ssize; i++){
        index = n;
        sort(strings.begin(),strings.end(),cmp);
    }
    return strings;
}