import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int testCase = Integer.parseInt(br.readLine());
        while(testCase --> 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            LinkedList<int[]> q = new LinkedList<>();
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<N; i++){
                // 초기 위치 , 중요도
                q.offer(new int[] { i, Integer.parseInt(st.nextToken())});
            }
            int count = 0;

            while(!q.isEmpty()){
                int[] front = q.poll();
                boolean isMax = true;
                for(int i=0; i<q.size(); i++){
                    if(front[1] < q.get(i)[1]){
                        q.offer(front);
                        for(int j=0; j<i; j++){
                            q.offer(q.poll());
                        }
                        isMax = false;
                        break;
                    }
                }

                if(isMax == false) continue;

                count++;
                if(front[0]== M) break;
            }
            sb.append(count).append('\n');

        }
        System.out.println(sb);
    }
}