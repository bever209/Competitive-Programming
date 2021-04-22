package kickstart;


import java.io.*;
import java.util.*;

public class round_B_3 {
    static class InputReader {
        BufferedReader buffreader;
        StringTokenizer strtokenizer;
        public InputReader(InputStream inputstr) {
            buffreader = new BufferedReader(new InputStreamReader(inputstr), 1000000);strtokenizer = null; }
        //////////////////////////////////////////////////////////////////////////////////////////
        String next() {
            while (strtokenizer == null || !strtokenizer.hasMoreTokens()) {
                try { strtokenizer = new StringTokenizer(buffreader.readLine()); }
                catch (IOException e) { throw new RuntimeException(e); }
            }
            return strtokenizer.nextToken(); }
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
    static boolean[] prime;
    public static void main(String[] args) {
        int t = r.nextInt();
        for (int v = 0; v < t; v++) {
            long x = r.nextLong();
            int n=(int)Math.sqrt(x)+50000;
            boolean[] prime= new boolean[(int)n + 1];
            Arrays.fill(prime,true);

            for (int p = 2; (long) p * p <= n; p++)
            {
                if (prime[p])
                {
                    for (int i = p * p; i <= n; i += p)
                        prime[i] = false;
                }
            }

            long num1=0;
            long num2=0;
            boolean check1=false;
            boolean check2=false;
            for (int i=prime.length-1;i>=0;i--){
                if (prime[i]){
                    if (!check1){
                        num1=i;check1=true;
                    }
                    else if (!check2){
                        num2=i;check2=true;
                        if (num1*num2>x){
                            check2=false;
                            num1=num2;
                        }
                        else{
                            long y=num1*num2;
                            pw.println("Case #"+(v+1)+": "+y);
                        }

                    }
                }
            }


        }
        pw.close();
    }
}
