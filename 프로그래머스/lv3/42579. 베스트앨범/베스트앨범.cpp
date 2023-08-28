#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i];
    }

    vector<pair<string, int>> genrePlays;
    for(auto it : m){
        genrePlays.push_back(make_pair(it.first, it.second));
    }
    sort(genrePlays.begin(), genrePlays.end(), cmp);

    for(auto genrePlay : genrePlays){
        string genre = genrePlay.first;
        vector<pair<int, int>> songInfo;

        for(int i = 0; i < genres.size(); i++){
            if(genres[i] == genre){
                songInfo.push_back(make_pair(i, plays[i]));
            }
        }

        sort(songInfo.begin(), songInfo.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        for(int i = 0; i < songInfo.size() && i < 2; i++){
            answer.push_back(songInfo[i].first);
        }
    }

    return answer;
}
