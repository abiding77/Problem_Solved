import java.util.*;
import java.io.*;

class Main {
    static int serial_num = 666;
    static int cnt = 1;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        while(cnt != N){ 
            serial_num++; 
            if(String.valueOf(serial_num).contains("666")){ 
                cnt++; 
            }
        }
        System.out.println(serial_num);
    }
}