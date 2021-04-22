package Educ_DP;


import java.io.*;
import java.util.*;

public class I {
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
        int a=r.nextInt();

        double[][] dp=new double[a+1][a+1];

        double prob[]=new double[a];
        for (int i=1;i<=a;i++){
            prob[i-1]=r.nextDouble();
        }
        dp[0][0]=1;

        for (int i=1;i<=a;i++){
            for (int j=0;j<=i;j++){
                double x=prob[i-1];
                dp[i][j]=dp[i-1][j]*(1-x);
                if (j!=0){
                    dp[i][j]=dp[i][j]+dp[i-1][j-1]*x;
                }
            }
        }

        double ans=0;
        for (int i=(a+1)/2;i<=a;i++){
            ans=ans+dp[a][i];
        }

        System.out.println(ans);
    }

}
