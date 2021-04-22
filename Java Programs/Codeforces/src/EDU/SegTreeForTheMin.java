package EDU;

import java.io.*;
import java.util.*;

public class SegTreeForTheMin {
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

    static int n=1;
    static long[] t;
    static long max=2000010000;
    public static void main(String[] args){
        n=r.nextInt();
        int q=r.nextInt();
        t=new long[4*n+400];
        Arrays.fill(t,max);
        for (int i=0;i<n;i++){
            set(i,r.nextLong());
        }
        build();
        for (int i=0;i<q;i++){
            int type=r.nextInt();
            if (type==1){
                set(r.nextInt(),r.nextLong());
            }
            else{
                System.out.println(query(r.nextInt(),r.nextInt()-1));
            }
        }
    }


    public static void build() { // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = Math.min(t[i << 1] , t[i << 1 | 1]);
    }

    public static void set(int p, long value) { // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = Math.min(t[p] , t[p ^ 1]); }


    public static long query(int l, int r) { // l and r are inclusive
        r++;long res = max;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) res =Math.min(t[l++],res);
            if ((r & 1) != 0) res =Math.min(t[--r],res);
        }
        return res;
    }
}
