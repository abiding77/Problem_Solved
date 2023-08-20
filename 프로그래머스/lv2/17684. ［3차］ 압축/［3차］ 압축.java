import java.util.*;
import java.io.*;
class Solution {
    public ArrayList<Integer> solution(String msg) {
        int[] answer = {};
        ArrayList<Integer> arr = new ArrayList<Integer>();
        int idx = 1;
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        for(char i='A'; i<='Z'; i++){
            map.put(i+"",idx);
            idx++;
        }
        int size = msg.length();
        for(int i=0; i<size; i++){
            int a = 1;
            while(i+a<=size && map.containsKey(msg.substring(i,i+a))){
                a++;
            }
            if(i+a>size){
                arr.add(map.get(msg.substring(i)));
                break;
            }
            arr.add(map.get(msg.substring(i,i+a-1)));
            map.put(msg.substring(i,i+a), idx++);
            if(a>1) i+= a-2;
        }
        
        return arr;
    }
}