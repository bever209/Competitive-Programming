package round_711;


import java.io.*;
import java.util.*;

public class C {
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
    static int mod=1000000007;
    public static void main(String[] args){
        int t=r.nextInt();
        for (int v=0;v<t;v++){
            int n=r.nextInt();
            int age=r.nextInt();

            int[] arr=new int[n-1];
            Arrays.fill(arr,1);

            long ans=0;
            if (n==1){
                if (age>1){
                    pw.println(2);
                }
                else{
                    pw.println(1);
                }
            }
            else if (age==1){
                pw.println(1);
            }
            else {

                for (int i = age - 1; i > 0; i--) {

                    for (int j:arr){
                        ans=(ans+j)%mod;
                    }


                    int sum = 0;
                    if (i % 2 != age % 2) {
                        for (int j = arr.length - 1; j >= 0; j--) {
                            sum = (sum + arr[j]) % mod;
                            arr[j] = sum;
                        }
                    } else {
                        for (int j = 0;j<arr.length; j++) {
                            sum = (sum + arr[j]) % mod;
                            arr[j] = sum;
                        }
                    }

                }
                ans=ans+2;
                pw.println(ans);
            }
        }
        pw.close();





    }
}
