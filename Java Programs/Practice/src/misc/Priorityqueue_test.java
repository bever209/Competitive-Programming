package misc;


import java.io.*;
import java.util.*;

public class Priorityqueue_test {
    public static class Pair{
        int x;
        int y;
        public Pair(int a,int b){
            x=a;
            y=b;
        }
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 1000000);
            tokenizer = null; }
        //////////////////////////////////////////////////////////////////////////////////////////
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken(); }
        ///////////////////////////////////////////////////////////////////////////////////////////
        public int nextInt() { return Integer.parseInt(next()); }
        public long nextLong() { return Long.parseLong(next()); }
        public double nextDouble() { return Double.parseDouble(next()); }
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args){
        PriorityQueue<Pair> q=new PriorityQueue<Pair>(Comparator.comparingInt(o->-o.x));
        q.add(new Pair(1,2));
        q.add(new Pair(2,-10));
        for (Pair i:q){
            System.out.println(i.x);
        }
    }
}
