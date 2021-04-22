package year_2020_2021;


import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class s_Open_1 {
    static class InputReader {
        BufferedReader buffreader;
        StringTokenizer strtokenizer;
        public InputReader(InputStream inputstr) {
            buffreader = new BufferedReader(new InputStreamReader(inputstr), 1000000);strtokenizer = null; }
        //////////////////////////////////////////////////////////////////////////////////////////
        String next() {
            while (strtokenizer == null || !strtokenizer.hasMoreTokens()) {
                try { strtokenizer = new StringTokenizer(buffreader.readLine()); }
                catch (IOException e) { throw new RuntimeException(e); }
            }
            return strtokenizer.nextToken(); }
        ///////////////////////////////////////////////////////////////////////////////////////////
        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
        public int[] nextIntArr(int n){
            int[] arr=new int[n];
            for (int i=0;i<n;i++){arr[i]=nextInt();}
            return arr;}
        public long[] nextLongArr(int n){
            long[] arr=new long[n];
            for (int i=0;i<n;i++){arr[i]=nextLong();}
            return arr;}
        public String[] nextStringArr(int n){
            String[] arr=new String[n];
            for (int i=0;i<n;i++){arr[i]=next();}
            return arr;}
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    static String[][] grid;
    static String[][] tt_board=new String[3][3];
    static boolean[][] visited;
    static int ans=0;
    public static void main(String[] args){


        int n=r.nextInt();
        grid=new String[n][n];

        int row=0;int col=0;
        for (int i=0;i<n;i++){
            String x=r.next();
            for (int j=0;j<3*n;j=j+3){
                grid[i][j/3]=x.substring(j,j+3);
                if (grid[i][j/3].charAt(0)=='B'){
                    row=i;col=j/3;
                }
            }

        }
        visited=new boolean[n][n];
        floodfill(row,col);


        pw.println(ans*ans*2);
        pw.close();






    }
    public static boolean done(String[][] board){
        ArrayList<String> list=new ArrayList<>();
        list.add(board[0][0]+board[0][1]+board[0][2]);
        list.add(board[0][0]+board[1][0]+board[2][0]);
        list.add(board[0][0]+board[1][1]+board[2][2]);
        list.add(board[1][0]+board[1][1]+board[1][2]);
        list.add(board[2][0]+board[2][1]+board[2][2]);
        list.add(board[0][1]+board[1][1]+board[2][1]);
        list.add(board[0][2]+board[1][2]+board[2][2]);
        list.add(board[0][2]+board[1][1]+board[2][0]);

        for (String i:list){
            if (i.equals("MOO")||i.equals("OOM")){
                return true;
            }
        }
        return false;
    }
    public static void floodfill(int row, int col){
        visited[row][col]=true;
        String a=grid[row][col];

        if (grid[row][col].charAt(0)!='.' && a.charAt(0)!='B'){

            String x=a.substring(0,1);
            int r=Integer.parseInt(a.substring(1,2))-1;
            int c=Integer.parseInt(a.substring(2,3))-1;
            tt_board[r][c]=x;
            if (done(tt_board)){
                ans++;
            }
        }

        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if (i==0 || j==0){
                    int new_r=row+i;
                    int new_c=col+j;
                    if (grid[new_r][new_c].charAt(0)!='#' && !visited[new_r][new_c]){
                        floodfill(new_r,new_c);
                    }
                }
            }
        }


    }
}
