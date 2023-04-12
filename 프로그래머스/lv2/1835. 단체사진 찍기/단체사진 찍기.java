import java.util.*;

class Solution {
    static HashMap<Character, Integer> map;
    static String[] d;
    static boolean[] vis;
    static int[] ch;
    static int answer;
    public int solution(int n, String[] data) {
        d = data;
        map = new HashMap<>();
        vis = new boolean[8];
        ch = new int[8];
        answer = 0;
        map.put('A',0);
        map.put('C',1);
        map.put('F',2);
        map.put('J',3);
        map.put('M',4);
        map.put('N',5);
        map.put('R',6);
        map.put('T',7);
        DFS(0);
        return answer;
    }
    static void DFS(int idx){
        if(idx==8){
            if(check()) answer++;
        }
        else{
            for(int i=0; i<8; i++){
                if(!vis[i]){
                    vis[i] = true;
                    ch[idx] = i;
                    DFS(idx+1);
                    vis[i] = false;
                }
            }
        }
    }
    static boolean check(){
        int a,b,res;
        char op;
        for(String s : d){
            a = ch[map.get(s.charAt(0))];
            b = ch[map.get(s.charAt(2))];
            op = s.charAt(3);
            res = s.charAt(4) - '0' + 1;
            
            if(op == '='){
                if(Math.abs(a-b)!= res)
                    return false;
            }
            else if (op == '>'){
                if(Math.abs(a-b) <= res)
                    return false;
            }
            else {
                if(Math.abs(a-b) >= res)
                    return false;
            }
        }
        return true;
    }
}