package range_queries;

import java.io.*;
import java.util.*;

public class RangeMin2 {
    static long[] t;
    static int n=1;
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 5000000);
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
    public static void main(String[] args) {
        n=r.nextInt();
        t=new long[4*n+400];
        Arrays.fill(t,2000000000);
        int q=r.nextInt();
        for (int i=0;i<n;i++){
            set(i,r.nextInt());
        }
        for (int i=0;i<q;i++){
            int t=r.nextInt();
            if (t==1){
                int ind=r.nextInt()-1;int val=r.nextInt();
                set(ind,val);
            }
            else{
                pw.println(query(r.nextInt()-1,r.nextInt()));
            }
        }
        pw.close();
    }

    public static void build() { // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = Math.min(t[i << 1], t[i << 1 | 1]);
    }

    public static void add(int p, long value) { // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = Math.min(t[p], t[p ^ 1]); }
    public static void set(int p, long value){// set at position p, value
        add(p,value);}

    public static long query(int l, int r) { // sum on interval [l, r) (0-INDEXED)
        long res = 2000000000;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) res=Math.min(res,t[l++]);
            if ((r & 1) != 0) res=Math.min(res,t[--r]);
        }
        return res;
    }
}
