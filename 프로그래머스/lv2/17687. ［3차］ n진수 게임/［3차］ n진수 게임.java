class Solution {
    public String solution(int n, int t, int m, int p) {
        StringBuilder answer = new StringBuilder();
        StringBuilder convert = new StringBuilder();
        for(int i=0; convert.length() <= t*m; i++){
            convert.append(Integer.toString(i,n));
        }
        //System.out.println(convert);
        for(int i=p-1; i<t*m; i+=m){
            answer.append(convert.charAt(i));
        }
        return answer.toString().toUpperCase();
    }
}