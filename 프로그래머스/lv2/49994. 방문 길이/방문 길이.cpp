#include <string>
#include <set>
#include <utility>

using namespace std;

int solution(string dirs) {
    int x = 0;
    int y = 0;
    int from[2];
    int to[2];
    set<pair<pair<int,int>, pair<int,int>>> answer;
    for(int i=0; i<dirs.length(); i++){
        from[0] = x;
        from[1] = y;
        if(dirs[i] == 'U' && y < 5){
            y++;
        } else if(dirs[i] == 'D' && y > -5){
            y--;
        } else if(dirs[i] == 'R' && x < 5){
            x++;
        } else if(dirs[i] == 'L' && x > -5){
            x--;
        } else {
            continue;
        }
        to[0] = x;
        to[1] = y;
        
        answer.insert(make_pair(make_pair(to[0],to[1]),make_pair(from[0],from[1])));
        answer.insert(make_pair(make_pair(from[0],from[1]),make_pair(to[0],to[1])));
    }
    return answer.size() / 2;
}