import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int ssize = prices.length;
        int[] answer = new int[ssize];
        for(int i=0; i<ssize; i++){
            for(int j=i+1; j<ssize; j++){
                answer[i]++;
                if(prices[i] > prices[j])
                    break;
            }
        }
        
        return answer;
    }
}