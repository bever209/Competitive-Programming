package range_queries;


import java.io.*;
import java.util.*;

public class RangeMin1 {
    static long max=1000000000;
    static int n;
    static long[] t;
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

        n=r.nextInt();
        int q=r.nextInt();
        long minpow=1;
        while (minpow<n){
            minpow=minpow*2;
        }
        t=new long[2*(int)minpow];
        for (int i=0;i<n;i++){
            t[i+n]=r.nextLong();
        }
        long c=t.length-1;
        while (t[(int)c]==0){
            t[(int)c]=max;
            c--;
        }
        build();
        for (int i=0;i<q;i++){
            pw.println(query(r.nextInt()-1,r.nextInt()));
        }
        pw.close();

    }
    public static void build() { // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = Math.min(t[i << 1], t[i << 1 | 1]);
    }


    public static long query(int l, int r) { // sum on interval [l, r) (0-INDEXED)
        long res = max;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) res=Math.min(res,t[l++]);
            if ((r & 1) != 0) res=Math.min(res,t[--r]);
        }
        return res;
    }


}
