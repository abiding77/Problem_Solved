import java.util.*;

class Solution
{
    public int solution(String s)
    {
        int answer = -1;
        Stack<Character> stack = new Stack<>();
        char[] arr = s.toCharArray();
        int ssize = s.length();
        for(int i=0; i<ssize; i++){
            char c = arr[i];
            if(stack.isEmpty()) stack.push(c);
            else {
                if(stack.peek() == c){
                    stack.pop();
                }
                else {
                    stack.push(c);
                }
            }
        }
        if(stack.isEmpty())
            answer = 1;
        else
            answer = 0;

        return answer;
    }
}