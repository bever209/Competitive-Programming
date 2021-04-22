package range_queries;


import java.io.*;
import java.util.*;

public class RangeSum2 {
    static long[] fwt;
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        String next() { // reads in the next string
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() { return Integer.parseInt(next()); } // reads in the next int
        public long nextLong() { return Long.parseLong(next()); } // reads in the next long
        public double nextDouble() { return Double.parseDouble(next()); } // reads in the next double
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args){

        int n=r.nextInt();
        int q=r.nextInt();
        long[] arr=new long[n+1];
        fwt=new long[n+1];
        for (int i=0;i<n;i++){
            long b=r.nextLong();
            update(i+1,b);
            arr[i+1]=b;
        }
        for (int i=0;i<q;i++){
            int num=r.nextInt();
            if (num==1){
                int ind=r.nextInt();
                long val=r.nextLong();
                update(ind,val-arr[ind]);
                arr[ind]=val;
            }
            else{
                pw.println(query(r.nextInt(),r.nextInt()));
            }

        }
        pw.close();

    }
    public static long query(int a, int b) {
        return sum(b) - sum(a - 1);
    }
    public static long sum(int i) {
        long sum = 0;
        while (i > 0) {
            sum += fwt[i];
            i -= (i & -i); //least important bit
        }
        return sum;
    }
    public static void update(int i, long v) {
        while (i > 0 && i < fwt.length) {
            fwt[i] += v;
            i += (i & -i);
        }
    }

}
