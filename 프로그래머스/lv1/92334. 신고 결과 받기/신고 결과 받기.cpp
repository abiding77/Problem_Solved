#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    map<string,int> id_list_idx;
    map<string, set<string>> report_list;
    // 유저 리스트 인덱스 저장
    for(int i=0; i<id_list.size(); i++){
        id_list_idx[id_list[i]] = i;
    }
    // 신고 결과 파싱 후 저장
    // 신고 당한 사람 , 신고한 사람
    for(int i=0; i<report.size(); i++){
        stringstream ss(report[i]);
        string from, to;
        while(ss >> from >> to){
            report_list[to].insert(from);
        }
    }
    for(auto iter : report_list){
        if(iter.second.size() >= k){
            for(auto in_iter : iter.second){
                answer[id_list_idx[in_iter]]++;
            }
        }
    }
    return answer;
}