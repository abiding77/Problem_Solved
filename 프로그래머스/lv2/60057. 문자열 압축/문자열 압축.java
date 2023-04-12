import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = s.length();
        for(int i=1; i<=s.length()/2; i++){ // 문자 절반만큼 돌리고
            String target = s.substring(0,i); // 첫 타겟 문자
            String cur = ""; // 현재 문자
            int cnt = 1; // 카운트
            StringBuilder sb = new StringBuilder(); // 문자열 연산이 많으므로 
            for(int start = i; start<=s.length(); start+=i){
                if(start + i >= s.length()){      
                    cur = s.substring(start,s.length());
                } else {
                    cur = s.substring(start,start+i);
                }
                
                if(cur.equals(target)){
                    cnt++;
                }
                else if (cnt==1) {
                    sb.append(target);
                    target = cur;
                }
                else {
                    sb.append(cnt).append(target);
                    target = cur;
                    cnt = 1;
                }
            }
            if( i != target.length()) sb.append(target);
            answer = Math.min(answer, sb.toString().length());
        }
        return answer;
    }
}