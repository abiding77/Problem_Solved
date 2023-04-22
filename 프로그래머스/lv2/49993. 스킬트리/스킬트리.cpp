#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> tree;
    for(int i=0; i<skill.length(); i++)
        tree[skill[i]] = i+1;
    
    for(int i=0; i<skill_trees.size(); i++){
        int count = 1;
        bool check = true;
        for(int j=0; j<skill_trees[i].length(); j++){
            if(tree[skill_trees[i][j]] > count){
                check = false;
                break;
            } else if(tree[skill_trees[i][j]] == count){
                count++;
            }
        }
        if(check)
            answer++;
    }
    return answer;
}