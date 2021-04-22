package algorithms2;


import java.io.*;
import java.util.*;

public class InversionsOnArray {
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
    static int n=1;
    static int[] fwt;
    static int[] arr;
    public static void main(String[] args){
        n=r.nextInt();
        arr=r.nextIntArr(n);
        fwt=new int[n+5];

        int ans=0;
        add(arr[0],1);
        for (int i=1;i<arr.length;i++){
            add(arr[i],1);
            ans=ans+(int)query(arr[i]+1,n);
        }
        pw.println(ans);
        pw.close();

    }

    public static long query(int a, int b) {
        return sum(b) - sum(a - 1);
    } // range [a,b]
    public static long sum(int i) {
        long sum = 0;
        while (i > 0) {
            sum += fwt[i];
            i -= (i & -i); //least important bit
        }
        return sum;
    }
    public static void set(int i,long v){add(i,v-arr[i]);}
    public static void add(int i, long v) {
        while (i <=n) {
            fwt[i] += v;
            i += (i & -i);
        }
    }
}
