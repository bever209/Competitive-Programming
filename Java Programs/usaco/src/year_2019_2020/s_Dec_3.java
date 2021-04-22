package year_2019_2020;


import java.io.*;
import java.util.*;

public class s_Dec_3 {
    static boolean visit[];
    static ArrayList<Integer>[] list;
    static int[] comp;
    static String[] val;
    static int count=0;
    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(new FileWriter("milkvisits.out"));

        int a=r.nextInt();
        int q=r.nextInt();

        val=new String[a];
        comp=new int[a];
        list=new ArrayList[a];
        visit=new boolean[a];

        String x=r.next();
        for (int i=0;i<x.length();i++){
            val[i]=x.substring(i,i+1);
            list[i]=new ArrayList<Integer>();
        }


        for (int i=0;i<a-1;i++){
            list[r.nextInt()-1].add(r.nextInt()-1);
        }

        for (int i=0;i<a;i++){
            if (!visit[i]){
                dfs(i);
                count++;
            }
        }

        //String ans="";
        for (int i=0;i<q;i++){
            int beg=r.nextInt()-1;
            int end=r.nextInt()-1;
            String v=r.next();
            if (comp[beg]!=comp[end]){
                pw.print("1");
                //ans=ans+"1";
            }
            else{
                if (val[beg].equals(v)){
                    pw.print("1");
                    //ans=ans+"1";
                }
                else{
                    pw.print("0");
                    //ans=ans+"0";
                }
            }
        }
        //pw.println(ans);
        pw.println();
        pw.close();





    }
    public static void dfs(int node){
        visit[node]=true;
        comp[node]=count;
        for (int i:list[node]){
            if (val[node].equals(val[i])){
                dfs(i);
            }
        }
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new FileReader("C:\\Users\\User\\Documents\\Programs\\java_programs\\usaco\\src\\year_2019_2020\\milkvisits.in"));
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
