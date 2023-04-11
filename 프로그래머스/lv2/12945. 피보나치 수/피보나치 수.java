class Solution {
    public int solution(int n) {
        int answer = 0;
        int m = 1234567;
        int[] fibo = new int[100001];
        fibo[0] = 0;
        fibo[1] = 1;
        for(int i=2; i<=n; i++){
            fibo[i] = (fibo[i-1] + fibo[i-2]) % m;
        }
        answer = fibo[n];
        return answer;
    }
}