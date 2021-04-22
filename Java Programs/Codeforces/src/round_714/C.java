//package round_714;



import java.io.*;
import java.util.StringTokenizer;

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
    static long mod=1000000007;
    static long[] vals=new long[2*100100];
    public static void main(String[] args){

        int t=r.nextInt();
        calc();
        for (int v=0;v<t;v++){
            int n=r.nextInt();
            int m=r.nextInt();

            long ans=0;

            while (n>0){
                ans=(ans+find(n%10-1+m))%mod;n=n/10;

            }
            pw.println(ans);



        }
        pw.close();

    }
    public static long find(int num){
        return vals[num]%mod;

    }
    public static void calc(){
        for (int i=0;i<9;i++){
            vals[i]=1;
        }
        vals[9]=2;
        for (int i=10;i<vals.length;i++){
            vals[i]=(vals[i-9]+vals[i-10])%mod;
        }
    }

}
