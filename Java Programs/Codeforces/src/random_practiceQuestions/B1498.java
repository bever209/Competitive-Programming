package random_practiceQuestions;


import java.io.*;
import java.util.*;

public class B1498 {
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
            int width=r.nextInt();
            int[] weights=r.nextIntArr(n);

            int[] powers=new int[21];
            for (int i:weights){
                int count=0;
                while (i>1){
                    i=i/2;count++;
                }
                powers[count]++;
            }

            int ans=0;
            for (int i=powers.length-1;i>=0;i--){
                if (powers[i]>0){
                    while (powers[i]>0) {
                        ans++;
                        int remain=width;

                        for (int j = i; j >= 0 && remain>0; j--) {
                            int x=(int)Math.pow(2,j);
                            int num=Math.min(powers[j],remain/x);
                            int sub=num*(int)Math.pow(2,j);
                            powers[j]=powers[j]-num;
                            remain=remain-sub;
                        }
                    }
                }
            }
            pw.println(ans);
        }
        pw.close();



    }
}
