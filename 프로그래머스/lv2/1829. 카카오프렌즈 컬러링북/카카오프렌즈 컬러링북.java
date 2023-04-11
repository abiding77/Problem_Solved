import java.util.*;

class Solution {
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    static class Node{
        int x;
        int y;
        public Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static Queue<Node> q = new LinkedList<Node>();
    static boolean[][] vis;
    static int num = 0;
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        vis = new boolean[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(picture[i][j] != 0 && !vis[i][j]){
                    num = 1;
                    BFS(picture,i,j,m,n);
                    numberOfArea++;
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea,num);
                }
            }
        }
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    static void BFS(int[][] picture, int x, int y, int m, int n){
        q.add(new Node(x,y));
        vis[x][y] = true;
        while(!q.isEmpty()){
            Node now = q.poll();
            for(int dir =0; dir<4; dir++){
                int nx = now.x + dx[dir];
                int ny = now.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(picture[nx][ny] == picture[x][y] && !vis[nx][ny]){
                    q.add(new Node(nx,ny));
                    vis[nx][ny] = true;
                    num++;
                }
            }
        }
    }
}