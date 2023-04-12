import java.util.*;

class Solution {
    static int maxNumOfSubscribers;
    static int maxSalesOfEmoticons;
    static int[] salesRatePolicy = {40,30,20,10};
    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = new int[2];
        DFS(0,emoticons.length,new int[emoticons.length],users,emoticons);
        answer[0] = maxNumOfSubscribers;
        answer[1] = maxSalesOfEmoticons;
        return answer;
    }
    static void DFS(int current, int num ,int[] input, int[][] users, int[] emoticons){
        if(current == num){
            int numOfSubscribers = 0;
            int salePrice = 0;
            for(int[] user : users){
                int userDiscountRate = user[0];
                int userLimit = user[1];
                int sum = 0;
                for(int i=0; i<input.length; i++){
                    if(input[i] >= userDiscountRate){
                        sum += emoticons[i] * (100 - input[i]) / 100;
                    }
                }
                if(sum >= userLimit) numOfSubscribers++;
                else salePrice += sum;
            }
            if(maxNumOfSubscribers < numOfSubscribers){
                maxNumOfSubscribers = numOfSubscribers;
                maxSalesOfEmoticons = salePrice;
            } else if(maxNumOfSubscribers == numOfSubscribers){
                maxSalesOfEmoticons = Math.max(maxSalesOfEmoticons,salePrice);
            }
            return;
        }
        for(int i=0; i<4; i++){
            input[current] = salesRatePolicy[i];
            DFS(current+1,num,input,users,emoticons);
        }
    }
}