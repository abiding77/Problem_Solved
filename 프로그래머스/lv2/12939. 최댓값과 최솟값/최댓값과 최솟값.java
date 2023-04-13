import java.util.*;
class Solution {
    public String solution(String s) {
        String answer = "";
        String[] str = s.split(" ");
        int num = str.length;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(int i=0; i<num; i++){
            int number = Integer.parseInt(str[i]);
            
            min = Math.min(number,min);
            max = Math.max(number,max);
        }
        answer = min + " " + max;
        return answer;
    }
}