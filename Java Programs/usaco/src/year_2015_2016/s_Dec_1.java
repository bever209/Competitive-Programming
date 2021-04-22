package year_2015_2016;


import java.io.*;
import java.util.*;

public class s_Dec_1 {
    static int ans=1;
    static int n;
    static ArrayList<Pair>[][] arr;
    static boolean[][] visit;
    static boolean[][] able;
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("lightson.out"));

        n=r.nextInt();
        int m=r.nextInt();
        arr=new ArrayList[n][n];

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                arr[i][j]=new ArrayList<>();
            }
        }

        for (int i=0;i<m;i++){
            int x=r.nextInt()-1;
            int y=r.nextInt()-1;
            arr[x][y].add(new Pair(r.nextInt()-1,r.nextInt()-1));
        }
        visit=new boolean[n][n];
        able=new boolean[n][n];
        able[0][0]=true;
        dfs(0,0);
        pw.println(ans);
        pw.close();

    }
    public static void dfs(int x,int y){
        visit[x][y]=true;
        for (Pair i:arr[x][y]){
            if (!able[i.x][i.y]){
                ans++;
                able[i.x][i.y]=true;
                if (has(i.x,i.y) && !visit[i.x][i.y]){
                    dfs(i.x,i.y);
                }
            }

        }
        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if (i==0 || j==0){
                    int valx=x+i;
                    int valy=y+j;
                    if (poss(valx,valy) && !visit[valx][valy] && able[valx][valy]){
                        dfs(valx,valy);
                    }
                }
            }
        }

    }
    public static boolean has(int x, int y){
        for (int i=-1;i<=1;i++){
            for (int j=-1;j<=1;j++){
                if (i==0 || j==0 && poss(x+i,y+j)){
                    if (poss(x+i,y+j)&&visit[i + x][y + j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    public static boolean poss(int x, int y){
        return x>=0 && y>=0 && x<n && y<n;
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\lightson.in"));

            tokenizer = null;
        }
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
    }
}
