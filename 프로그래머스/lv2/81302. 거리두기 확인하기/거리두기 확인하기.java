import java.util.*;

class Solution {
    int[] dx = {1,0,-1,0};
    int[] dy = {0,1,0,-1};
    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];
        for(int i=0; i<places.length; i++){
            answer[i] = isCorrect(places[i]);
        }
        return answer;
    }
    public int isCorrect(String[] board){
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[i].length(); j++){
                if(board[i].charAt(j) == 'P'){
                    if(!BFS(board,i,j)) return 0;
                }
            }
        }
        return 1;
    }
    public boolean BFS(String[] board, int x, int y){
        Queue<Node> Q = new LinkedList<>();
        boolean[][] visited = new boolean[board.length][board.length];
        Q.offer(new Node(x,y));
        visited[x][y] = true;
        while(!Q.isEmpty()){
            int curX = Q.peek().x;
            int curY = Q.peek().y;
            Q.poll();
            for(int i=0; i<4; i++){
                int nx = curX + dx[i];
                int ny = curY + dy[i];
                int d = Math.abs(x-nx) + Math.abs(y-ny);
                if(nx < 0 || ny < 0 || nx>=5 || ny>=5) continue;
                if(visited[nx][ny] || d > 2) continue;
                
                visited[nx][ny] = true;
                if(board[nx].charAt(ny) == 'X') continue;
                else if(board[nx].charAt(ny) == 'P') return false;
                else Q.offer(new Node(nx,ny));
                }
            }
        return true;
    }
    public class Node {
        int x;
        int y;
        
        Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
