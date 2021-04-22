//package round_714;



import java.io.*;
import java.util.*;

public class B {
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
    static long mod=1000000007;
    public static void main(String[] args){
        int t=r.nextInt();
        for (int v=0;v<t;v++){
            int n=r.nextInt();
            int[] arr=r.nextIntArr(n);
            int f=(int)Math.pow(2,30)-1;
            for (int i:arr){
                f=f&i;
            }
            boolean check=true;
            for (int i:arr){
                if ((i&f)!=f){
                    check=false;break;
                }
            }

            long c=0;
            for (int i:arr){
                if (i==f){
                    c++;
                }
            }
            long ans=0;

            if (c>1 && check){
                ans=(((c)*(c-1)%mod)*(fact(n-2)%mod))%mod;


            }
            pw.println(ans);


        }
        pw.close();



    }
    public static long fact(int n){
        long ans=1;
        for (int i=1;i<=n;i++){
            ans=(ans*i)%mod;
        }
        return ans%mod;
    }

}
