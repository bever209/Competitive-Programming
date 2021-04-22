package algorithms;
// THIS IS A STRING ALGORITHM

import java.io.*;
import java.util.*;

public class Z_algo {
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

        String x=r.next();
        int[] list=z(x);
        for (int i:list){
            System.out.print(i+" ");
        }

    }
    public static int[] z(String x){
        int n=x.length();
        int[] z=new int[n];
        int l=0,r=0;
        for (int i=1;i<n;i++){
            if (i<=r){
                z[i]=Math.min(r-i+1,z[i-l]);
            }
            while (i+z[i]<n && x.charAt(z[i])==x.charAt(z[i]+i)){
                ++z[i];
            }
            if (i+z[i]>r+1){
                l=i;
                r=i+z[i]-1;
            }
        }
        return z;
    }
}
