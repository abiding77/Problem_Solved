import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer sub = new StringTokenizer(br.readLine(),"-");
        int sum = Integer.MAX_VALUE;
        while(sub.hasMoreTokens()){
            int temp = 0;
            StringTokenizer add = new StringTokenizer(sub.nextToken(),"+");
            while(add.hasMoreTokens()){
                temp += Integer.parseInt(add.nextToken());
            }
            if(sum == Integer.MAX_VALUE)
                sum = temp;
            else
                sum -= temp;
        }
        System.out.println(sum);
    }
}