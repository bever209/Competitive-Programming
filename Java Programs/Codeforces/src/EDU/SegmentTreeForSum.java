package EDU;


import java.io.*;
import java.util.StringTokenizer;

public class SegmentTreeForSum {
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
    static long[] fwt;
    static long[] arr;
    public static void main(String[] args){
        n=r.nextInt();
        int q=r.nextInt();
        fwt=new long[n+5];
        arr=new long[n+1];
        for (int i=0;i<n;i++){
            long c=r.nextLong();
            set(i+1,c);
            arr[i+1]=c;
        }

        for (int i=0;i<q;i++){
            int type=r.nextInt();
            if (type==1){
                int p=r.nextInt()+1;long x=r.nextLong();
                set(p,x);
                arr[p]=x;
            }
            else{
                System.out.println(query(r.nextInt()+1,r.nextInt()));
            }
        }
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
