package year_2017_2018;


import java.io.*;
import java.util.*;

public class s_Jan_3 {
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }
    static int k;
    static int ans;
    static boolean[] visit;
    static ArrayList<Pair>[] arr;
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("mootube.out"));

        int n=r.nextInt();
        int q=r.nextInt();

        arr=new ArrayList[n];
        for (int i=0;i<n;i++){
            arr[i]=new ArrayList<>();
        }
        for (int i=0;i<n-1;i++){
            int a=r.nextInt()-1;int b=r.nextInt()-1;int c=r.nextInt();
            arr[a].add(new Pair(b,c));
            arr[b].add(new Pair(a,c));
        }

        visit=new boolean[n];
        for (int i=0;i<q;i++){
            Arrays.fill(visit,false);
            ans=0;
            k=r.nextInt();
            int v=r.nextInt()-1;

            dfs(v,k+1);
            pw.println(ans);

        }
        pw.close();
    }
    public static void dfs(int node, int r){
        visit[node]=true;
        for (Pair i:arr[node]){
            int other=i.x;
            int weight=i.y;
            if (!visit[other]) {
                if (weight >= k) {
                    ans++;
                    dfs(other,Math.min(weight,r));
                }
            }
        }
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2017_2018\\mootube.in"));
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
