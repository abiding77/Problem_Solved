import java.util.*;

class Solution {
    static int changeNum = 0;
    static int deleteZero = 0;
    public int[] solution(String s) {
        int[] answer = new int[2];
        String tmp = s;
        while(!tmp.equals("1")){
            tmp = changeBinary(tmp);
            changeNum++;
        }
        answer[0] = changeNum;
        answer[1] = deleteZero;
        return answer;
    }
    public String changeBinary(String s){
        int size = s.length();
        String tmp = "";
        for(int i=0; i<size; i++){
            if(s.charAt(i)=='0'){
                deleteZero++;
                continue;
            } else tmp += String.valueOf(s.charAt(i));
        }
        int rsize = tmp.length();
        tmp = Integer.toString(rsize,2);
        return tmp;
    }
}