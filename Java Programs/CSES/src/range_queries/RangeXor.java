package range_queries;


import java.io.*;
import java.util.*;

public class RangeXor {
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
    static long[] pref;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args){
        int n=r.nextInt();
        int q=r.nextInt();
        long[] arr=new long[n];
        pref=new long[n];
        for (int i=0;i<n;i++){
            arr[i]=r.nextLong();
        }
        long val=0;
        for (int i=0;i<n;i++){
            val=val^arr[i];
            pref[i]=val;
        }
        for (int i=0;i<q;i++){
            pw.println(query(r.nextInt()-1,r.nextInt()-1));
        }
        pw.close();

    }
    public static long query(int a, int b){//inclusive on both sides
        if (a==0){
            return pref[b];
        }
        else{
            return pref[b]^pref[a-1];
        }
    }


}
