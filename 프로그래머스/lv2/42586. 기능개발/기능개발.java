class Solution {
    static int[] temp = new int[101];
    static int day = 0;
    public int[] solution(int[] progresses, int[] speeds) {
        for(int i=0; i<progresses.length; i++){
            while(progresses[i] + (speeds[i] * day) < 100){
                day++;
            }
            temp[day]++;
        }
        int count = 0;
        for(int n : temp){
            if(n!= 0){
                count++;
            }
        }
        int[] answer = new int[count];
        count = 0;
        for(int n : temp){
            if(n!=0){
                answer[count++] = n;
            }
        }
        return answer;
    }
}