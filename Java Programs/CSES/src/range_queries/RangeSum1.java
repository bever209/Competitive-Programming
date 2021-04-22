package range_queries;


import java.io.*;
import java.util.*;

public class RangeSum1 {
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

        int n=r.nextInt();int q=r.nextInt();

        long[] list=new long[n];
        for (int i=0;i<list.length;i++){
            list[i]=r.nextLong();
        }
        long[] pref=new long[n+1];
        long sum=0;
        for (int i=0;i<n;i++){
            sum=sum+list[i];
            pref[i+1]=sum;
        }
        for (int i=0;i<q;i++){
            int left=r.nextInt();
            int right=r.nextInt();

            pw.println(pref[right]-pref[left-1]);

        }
        pw.close();
    }

}
