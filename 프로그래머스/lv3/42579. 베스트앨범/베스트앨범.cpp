#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

bool cmp2(pair<int,int> a , pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> m;
    for(int i=0; i<genres.size(); i++){
        m[genres[i]] += plays[i];
    }
    vector<pair<string,int>> genresPlay;
    for(auto it : m){
        genresPlay.push_back({it.first,it.second});
    }
    sort(genresPlay.begin(), genresPlay.end(),cmp);
    for(auto genrePlay : genresPlay){
        string songName = genrePlay.first;
        vector<pair<int,int>> songInfo; // 인덱스 , 재생횟수
        for(int i=0; i<genres.size(); i++){
            if(songName == genres[i]){
                songInfo.push_back({i,plays[i]});
            }
        }
        sort(songInfo.begin(),songInfo.end(),cmp2);
        
        for(auto it : songInfo){
            cout << it.first << " " << it.second << '\n';
        }
        for(int i=0; i<songInfo.size() && i < 2 ; i++){
            answer.push_back(songInfo[i].first);
        }
    }
    return answer;
}