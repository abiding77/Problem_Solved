import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int cnt = 0;
        while(T>=5){
            cnt += T/5;
            T/=5;
        }
        System.out.println(cnt);
    }
}