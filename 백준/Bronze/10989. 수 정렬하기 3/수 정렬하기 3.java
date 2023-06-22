import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] cnt = new int[10001];
        for(int i=0; i<N; i++){
            cnt[Integer.parseInt(br.readLine())]++;
        }

        StringBuilder sb = new StringBuilder();
        for(int i=1; i<10001; i++){
            while(cnt[i] > 0){
                sb.append(i).append('\n');
                cnt[i]--;
            }
        }
        System.out.println(sb);
    }
}