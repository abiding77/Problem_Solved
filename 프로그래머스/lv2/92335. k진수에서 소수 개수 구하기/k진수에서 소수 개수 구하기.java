class Solution {
    public int solution(int n, int k) {
        int answer = 0;
        String s = changeNumber(n,k);
        String[] arr = s.split("0");
        for(String data : arr){
            if(data.equals("")) continue;
            long num = Long.parseLong(data);
            if(isPrime(num)) answer++;
        }
        return answer;
    }
    public String changeNumber(int n, int k){
        String res = "";
        while(n>0){
            res = n%k + res;
            n /= k;
        }
        return res;
    }
    public boolean isPrime(long k){
        if(k < 2) return false;
        else {
            for(int i=2; i<=Math.sqrt(k); i++){
                if(k%i==0) return false;
            }
        }
        return true;
    }
}