package year_2018_2019;


import java.io.*;
import java.util.*;

public class s_Open_3 {

    static int[][] coord;

    static ArrayList<Integer>[] arr;
    static int minx;
    static int maxx;
    static int miny;
    static int maxy;
    static boolean[] visit;

    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("fenceplan.out"));

        int n=r.nextInt();
        int m=r.nextInt();

        coord=new int[n][2];

        for (int i=0;i<n;i++){
            coord[i][0]=r.nextInt();
            coord[i][1]=r.nextInt();
        }

        arr=new ArrayList[n];
        for (int i=0;i<n;i++){
            arr[i]=new ArrayList<>();
        }
        for (int i=0;i<m;i++){
            int a=r.nextInt()-1;
            int b=r.nextInt()-1;
            arr[a].add(b);
            arr[b].add(a);
        }
        int ans=1000000000;
        visit=new boolean[n];
        for (int i=0;i<n;i++){
            if (!visit[i]){
                reset();
                dfs(i);

                ans=Math.min(ans,2*(maxx-minx+maxy-miny));

            }
        }
        pw.println(ans);
        pw.close();

    }
    public static void reset(){
         minx=100000001;
         maxx=-1;
         miny=100000001;
         maxy=-1;
    }
    public static void dfs(int node){
        visit[node]=true;
        maxx=Math.max(maxx,coord[node][0]);
        minx=Math.min(minx,coord[node][0]);
        miny=Math.min(miny,coord[node][1]);
        maxy=Math.max(maxy,coord[node][1]);
        for (int i:arr[node]){
            if (!visit[i]){
                dfs(i);
            }
        }
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2018_2019\\fenceplan.in"));
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
