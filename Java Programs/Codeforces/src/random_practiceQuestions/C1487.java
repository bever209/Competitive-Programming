package random_practiceQuestions;


import java.io.*;
import java.util.*;

public class C1487 {
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
    public static void main(String[] args){

            int t=r.nextInt();
            for (int v=0;v<t;v++){
                int n=r.nextInt();

                if (n%2==1){
                    for (int j=0;j<n;j++){
                        for (int i=j+1;i<n;i++){
                            if (i-j<=n/2){
                                pw.print("1 ");
                            }
                            else{
                                pw.print("-1 ");
                            }
                        }
                    }
                }
                else{
                    for (int j=0;j<n;j++){
                        for (int i=j+1;i<n;i++){
                            if (i-j<n/2){
                                pw.print("1 ");
                            }
                            else if (i-j==n/2){
                                pw.print("0 ");
                            }
                            else{
                                pw.print("-1 ");
                            }
                        }
                    }
                }
                pw.println();
            }
            pw.close();

    }
}
