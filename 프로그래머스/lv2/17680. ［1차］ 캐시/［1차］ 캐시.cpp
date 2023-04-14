#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int cityLen = cities.size();
    vector<string> cache;
    if(cacheSize == 0){
        answer = cityLen * 5;
        return answer;
    }
    for(int i=0; i<cityLen; i++){
        string city = cities[i];
        transform(city.begin(),city.end(),city.begin(),::tolower);
        auto it = find(cache.begin(),cache.end(),city);
        if(it != cache.end()){
            cache.erase(it);
            cache.push_back(city);
            answer++;
        } // 캐시에 없음
        else {
            if(cache.size() < cacheSize){
                cache.push_back(city);
            }
            else {
                cache.erase(cache.begin()+0);
                cache.push_back(city);
            }
            answer += 5;
        }
    }
    return answer;
}