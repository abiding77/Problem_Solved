import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        Stack<Integer> ST = new Stack();
        int ssize = prices.length;
        for(int i=0; i<ssize; i++){
            while(!ST.isEmpty() && prices[i] < prices[ST.peek()]){
                answer[ST.peek()] = i-ST.peek();
                ST.pop();
            }
            ST.push(i);
        }
        
        while(!ST.isEmpty()){
            answer[ST.peek()] = ssize - ST.peek() -1;
            ST.pop();
        }
        return answer;
    }
}