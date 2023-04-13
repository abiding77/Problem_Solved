#include <string>
#include <vector>
#include <locale>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    string buf;
    vector<string> v;
    stringstream sstream(s);
    while(getline(sstream,buf,' ')){
        v.push_back(buf);
    }
    for(int i=0;i<v.size();i++){
        string tmp = v[i];
        if(tmp[0]>='a'&&tmp[0]<='z'){
            tmp[0] = toupper(tmp[0]);
        }
        for(int j=1;j<tmp.length();j++){
            tmp[j] = tolower(tmp[j]);
        }
        
        answer+=tmp;
        answer+=' ';
    }
    if(s[s.length()-1]!=' ')
        answer=answer.substr(0,answer.size()-1);
    return answer;
}