package year_2015_2016;



import java.io.*;
import java.util.*;

public class s_Open_3 {


    static boolean[] remove;
    static boolean[] visit;
    static ArrayList<Integer>[] arr;
    public static void main(String[] args) throws IOException{
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("closing.out"));

        int n=r.nextInt();
        int e=r.nextInt();


        arr=new ArrayList[n];
        for (int i=0;i<n;i++){
            arr[i]=new ArrayList<>();
        }
        remove=new boolean[n];
        visit=new boolean[n];

        for (int i=0;i<e;i++){
            int a=r.nextInt()-1;
            int b=r.nextInt()-1;
            arr[a].add(b);
            arr[b].add(a);
        }

        for (int i=0;i<n;i++){
            Arrays.fill(visit,false);
            int count=0;
            for (int j=0;j<n;j++){
                if (!visit[j] && !remove[j]){
                    dfs(j);
                    count++;
                }
            }
            if (count==1){
                pw.println("YES");
            }
            else{
                pw.println("NO");
            }
            remove[r.nextInt()-1]=true;
        }
        pw.close();

    }
    public static void dfs(int node){
        visit[node]=true;
        for (int i:arr[node]){
            if (!visit[i] && !remove[i]){
                dfs(i);
            }
        }
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2015_2016\\closing.in"));
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